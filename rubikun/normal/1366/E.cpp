#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> A(N),B(M),mi(N+1);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];
    B.push_back(INF);
    
    ll ans=1;
    
    int id=M-1,last=N;
    bool flag=false;
    
    for(int i=N-1;i>=0;i--){
        
        if(A[i]<B[id]){
            if(!flag) ans=0;
            flag=false;
            
            ans*=(last-i);
            ans%=mod;
            
            id--;
        }
        
        if(id<0){
            ans=0;
            break;
        }
        
        if(A[i]<B[id]) ans=0;
        
        if(A[i]==B[id]){
            if(!flag){
                flag=true;
                last=i;
            }
        }
    }
    
    if(id) ans=0;
    
    sort(all(A));
    if(A[0]!=B[0]) ans=0;
    
    cout<<ans<<endl;
    
}