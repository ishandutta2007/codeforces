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
const int mod=1000000007,MAX=205,INF=1<<30;
bool G[MAX][MAX],can[MAX][MAX];
int mi[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll u,v;cin>>u>>v;
        bool ok=true;
        int a=0,b=0;
        for(int k=0;k<40;k++){
            if(u&(1LL<<k)) a++;
            if(v&(1LL<<k)) b++;
            if(a<b) ok=false;
        }
        if(u>v) ok=false;
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}