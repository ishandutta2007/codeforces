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
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<pair<int,int>> S(3);
    for(int i=0;i<3;i++){
        cin>>S[i].fi>>S[i].se;
    }
    sort(all(S));
    
    set<pair<int,int>> ans;
    
    for(int i=S[0].fi;i<=S[1].fi;i++) ans.insert(mp(i,S[0].se));
    for(int i=S[1].fi;i<=S[2].fi;i++) ans.insert(mp(i,S[2].se));
    
    for(int i=min(S[0].se,S[1].se);i<=max(S[0].se,S[1].se);i++) ans.insert(mp(S[1].fi,i));
    for(int i=min(S[2].se,S[1].se);i<=max(S[2].se,S[1].se);i++) ans.insert(mp(S[1].fi,i));
    
    cout<<si(ans)<<endl;
    for(auto a:ans) cout<<a.fi<<" "<<a.se<<"\n";
    
}