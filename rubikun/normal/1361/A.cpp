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
const int mod1=1000000007,MAX=500005,INF=1<<30;

vector<int> G[MAX];

int num[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> S(N);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        cin>>S[i].fi;
        S[i].se=i;
    }
    
    sort(all(S));
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        set<int> SE;
        for(int to:G[S[i].se]){
            if(num[to]) SE.insert(num[to]);
        }
        for(int j=1;j<S[i].fi;j++) if(SE.count(j)==0) ok=false;
        if(SE.count(S[i].fi)) ok=false;
        num[S[i].se]=S[i].fi;
        
        if(!ok) break;
    }
    
    if(!ok) cout<<-1<<endl;
    else{
        for(int i=0;i<N;i++) cout<<S[i].se+1<<" ";
        cout<<endl;
    }
}