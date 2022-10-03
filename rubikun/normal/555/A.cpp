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
const int INF=1<<30;
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    
    ll ans=0;
    
    vector<vector<int>> S(K);
    
    int ma=0;
    
    for(int i=0;i<K;i++){
        int x;cin>>x;
        S[i].resize(x);
        for(int j=0;j<x;j++) cin>>S[i][j];
        
        for(int j=0;j<x;j++){
            if(S[i][j]!=j+1){
                if(j==0) ans+=(x-1-j);
                else ans+=(x-j);
                break;
            }
            chmax(ma,j+1);
        }
    }
    
    ans+=N-ma;
    
    cout<<ans<<endl;
    
}