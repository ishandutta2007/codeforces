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
const int mod=998244353,MAX=150005,INF=1<<30;
vector<int> pos[MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<MAX;i++) pos[i].clear();
        for(int i=0;i<N;i++){
            int x;cin>>x;
            pos[x].push_back(i);
        }
        int ans=-1;
        for(int i=1;i<=150000;i++){
            for(int j=0;j+1<si(pos[i]);j++){
                chmax(ans,N-(pos[i][j+1]-pos[i][j]));
            }
        }
        cout<<ans<<"\n";
    }
}