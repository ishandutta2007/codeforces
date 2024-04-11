#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=210003;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int H;cin>>H;
    vector<int> A(H+1);
    int N=0;
    for(int i=0;i<H+1;i++){
        cin>>A[i];
        N+=A[i];
    }
    
    bool ok=true;
    for(int i=0;i<H;i++){
        if(A[i]>=2&&A[i+1]>=2) ok=false;
    }
    
    if(ok){
        cout<<"perfect\n";
        return 0;
    }
    
    cout<<"ambiguous\n";
    
    vector<int> B(H+1),ans1(N+1),ans2(N+1);
    B[0]=1;
    for(int i=1;i<H+1;i++){
        B[i]=B[i-1]+A[i-1];
        ans1[B[i]]=B[i-1];
    }
    
    for(int i=1;i<=N;i++){
        if(ans1[i]==0) ans1[i]=ans1[i-1];
    }
    
    ans2=ans1;
    
    for(int i=0;i<H;i++){
        if(A[i]>=2&&A[i+1]>=2){
            ans2[B[i+1]]++;
            break;
        }
    }
    
    for(int i=1;i<=N;i++){
        if(i>1) cout<<" ";
        cout<<ans1[i];
    }
    cout<<"\n";
    
    for(int i=1;i<=N;i++){
        if(i>1) cout<<" ";
        cout<<ans2[i];
    }
    cout<<"\n";
    
}