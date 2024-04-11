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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

vector<int> G[MAX];
bool used[MAX],can[MAX];
vector<int> V;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
    }
    
    for(int i=0;i<N;i++){
        if(used[i]) continue;
        V.push_back(i);
        can[i]=1;
        used[i]=1;
        for(int to:G[i]) used[to]=1;
    }
    
    vector<int> ans;
    
    reverse(all(V));
    
    for(int a:V){
        if(!can[a]) continue;
        ans.push_back(a);
        for(int to:G[a]) can[to]=0;
    }
    
    cout<<si(ans)<<endl;
    
    for(int a:ans) cout<<a+1<<" ";
    cout<<endl;
}