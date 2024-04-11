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
    
    int N;cin>>N;
    
    vector<pair<int,int>> ans;
    ans.push_back(mp(0,0));
    ans.push_back(mp(1,0));
    ans.push_back(mp(0,1));
    ans.push_back(mp(1,1));
    
    for(int i=1;i<=N;i++){
        ans.push_back(mp(i+1,i));
        ans.push_back(mp(i,i+1));
        ans.push_back(mp(i+1,i+1));
    }
    
    cout<<si(ans)<<"\n";
    for(int i=0;i<si(ans);i++){
        cout<<ans[i].fi<<" "<<ans[i].se<<"\n";
    }
}