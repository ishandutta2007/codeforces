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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        map<int,int> MA;
        for(int i=0;i<N;i++){
            int x;cin>>x;
            MA[x]++;
            chmin(MA[x],2);
        }
        vector<int> cnt(si(MA));
        int t=0;
        int al=0;
        for(auto a:MA){
            cnt[t]=a.se;
            t++;
            al+=a.se;
        }
        
        int ans=-1;
        int sum=0;
        for(int i=0;i<si(cnt);i++){
            chmax(ans,(al-cnt[i])/2+1);
            sum+=cnt[i];
        }
        
        cout<<ans<<"\n";
    }
}