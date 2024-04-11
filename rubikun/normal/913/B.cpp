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
const int mod=998244353,MAX=5005,INF=1<<28;

vector<int> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=1;i<N;i++){
        int p;cin>>p;
        p--;
        G[p].push_back(i);
    }
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        if(si(G[i])==0) continue;
        int cnt=0;
        for(int to:G[i]){
            if(si(G[to])==0) cnt++;
        }
        ok&=(cnt>=3);
    }
    
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}