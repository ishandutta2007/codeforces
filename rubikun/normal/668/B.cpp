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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    ll a=0,b=1;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            ll x;cin>>x;
            a+=N+x;
            b+=N+x;
            a%=N;
            b%=N;
        }else{
            a^=1;
            b^=1;
        }
    }
    
    vector<int> pos(N);
    pos[0]=a;
    for(int i=2;i<N;i++){
        pos[i]=(pos[i-2]+2)%N;
    }
    pos[1]=b;
    for(int i=3;i<N;i++){
        pos[i]=(pos[i-2]+2)%N;
    }
    
    vector<int> ans(N);
    for(int i=0;i<N;i++){
        ans[pos[i]]=i;
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]+1<<" ";
    cout<<endl;
}