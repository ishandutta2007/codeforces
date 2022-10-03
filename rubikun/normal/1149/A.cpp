#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=100000007,MAX=100005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N);
    int cnt1=0,cnt2=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]==1) cnt1++;
        else cnt2++;
    }
    
    if(cnt1>=3){
        for(int i=0;i<3;i++){
            cout<<1<<" ";
        }
        for(int i=0;i<cnt2;i++){
            cout<<2<<" ";
        }
        for(int i=0;i<cnt1-3;i++){
            cout<<1<<" ";
        }
        cout<<endl;
    }else if(cnt1>=1){
        if(cnt2==0){
            for(int i=0;i<cnt1;i++) cout<<1<<" ";
            cout<<endl;
        }else{
            cout<<"2 1 ";
            for(int i=0;i<cnt2-1;i++) cout<<2<<" ";
            for(int i=0;i<cnt1-1;i++) cout<<1<<" ";
            cout<<endl;
        }
    }else{
        for(int i=0;i<cnt2;i++) cout<<2<<" ";
        cout<<endl;
    }
}