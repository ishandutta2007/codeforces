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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        map<int,int> MA;
        int ma=0;
        for(int i=0;i<N;i++){
            int x;cin>>x;
            MA[x]++;
            chmax(ma,MA[x]);
        }
        int ans=0;
        while(ma<N){
            ans++;
            int nex=min(N,ma*2);
            ans+=nex-ma;
            ma=nex;
        }
        
        cout<<ans<<"\n";
        
    }
}