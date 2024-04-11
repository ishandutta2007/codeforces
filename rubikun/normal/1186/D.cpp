#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<double> A(N);
    vector<int> ans(N);
    ll sum=0;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==floor(A[i])) ans[i]=1;
        sum+=floor(A[i]);
    }
    
    ll need=0-sum;
    
    for(int i=0;i<N;i++){
        if(need&&ans[i]==0){
            ans[i]=floor(A[i])+1;
            need--;
        }else{
            ans[i]=floor(A[i]);
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<ans[i]<<"\n";
    }
}