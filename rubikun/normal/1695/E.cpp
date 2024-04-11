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
const int mod=998244353,MAX=600005,INF=1<<30;

vector<pair<int,int>> G[MAX];
bool seenv[MAX],seene[MAX];
vector<int> trail;

void DFS(int u){
    trail.push_back(u);
    if(seenv[u]) return;
    seenv[u]=true;
    
    for(pair<int,int> to:G[u]){
        if(seene[to.se]) continue;
        seene[to.se]=true;
        DFS(to.fi);
        trail.push_back(u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    if(N==1){
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(mp(b,i));
        G[b].push_back(mp(a,i));
    }
    
    vector<vector<int>> ans(2);
    vector<string> S(2),T(2);
    
    for(int i=0;i<2*N;i++){
        if(seenv[i]) continue;
        trail.clear();
        DFS(i);
        trail.pop_back();
        if(si(trail)==0) continue;
        if(si(trail)==2){
            cout<<-1<<"\n";
            return 0;
        }
        for(int j=0;j<si(trail)/2;j++) ans[0].push_back(trail[j]);
        for(int j=0;j<si(trail)/2;j++) ans[1].push_back(trail[si(trail)-1-j]);
        
        //for(int x:trail) cout<<x<<" ";
        //cout<<endl;
        if((si(trail)/2)&1){
            S[0]+='U';
            S[1]+='D';
            for(int j=1;j<si(trail)/2;j+=2){
                S[0]+="LR";
                S[1]+="LR";
            }
            for(int j=1;j<si(trail)/2;j+=2){
                T[0]+="LR";
                T[1]+="LR";
            }
            T[0]+='U';
            T[1]+='D';
        }else{
            //for(int x:trail) cout<<x<<" ";
            //cout<<endl;
            for(int j=0;j<si(trail)/2;j+=2){
                S[0]+="LR";
                S[1]+="LR";
            }
            T[0]+='U';
            T[1]+='D';
            for(int j=2;j<si(trail)/2;j+=2){
                T[0]+="LR";
                T[1]+="LR";
            }
            T[0]+='U';
            T[1]+='D';
        }
    }
    
    cout<<2<<" "<<si(ans[0])<<"\n";
    for(int i=0;i<2;i++){
        for(int x:ans[i]) cout<<x+1<<" ";
        cout<<"\n";
    }
    cout<<S[0]<<"\n";
    cout<<S[1]<<"\n";
    cout<<T[0]<<"\n";
    cout<<T[1]<<"\n";
    
}