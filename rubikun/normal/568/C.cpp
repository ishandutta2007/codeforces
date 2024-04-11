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

const int mod=1000000007,MAX=405,INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void add_clause(int i,bool f,int j,bool g){
    add_edge(2*i+(!f),2*j+g);
    add_edge(2*j+(!g),2*i+f);
}

void DFS(int v){
    used[v]=1;
    for(int i=0;i<G[v].size();i++){
        if(used[G[v][i]]==0) DFS(G[v][i]);
    }
    vs.push_back(v);
}

void rDFS(int v,int k){
    used[v]=1;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(used[rG[v][i]]==0) rDFS(rG[v][i],k);
    }
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}

vector<int> G2[MAX];

bool use[MAX];

void DFS2(int u){
    if(use[u]) return;
    use[u]=1;
    for(int to:G2[u]){
        DFS2(to);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int L=si(S);
    int N,M;cin>>N>>M;
    
    V=2*N;
    
    for(int i=0;i<M;i++){
        int a,b,c,d;char bb,dd;cin>>a>>bb>>c>>dd;
        a--;c--;
        if(bb=='C') b=1;
        else b=0;
        
        if(dd=='C') d=1;
        else d=0;
        
        add_clause(a,!b,c,d);
        
    }
    
    string T;cin>>T;
    
    scc();
    
    for(int i=0;i<N;i++){
        if(cmp[2*i]==cmp[2*i+1]){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    set<pair<int,int>> SE;
    
    for(int i=0;i<2*N;i++){
        for(int to:G[i]){
            if(cmp[i]!=cmp[to]) SE.insert(mp(cmp[i],cmp[to]));
        }
        //cout<<cmp[i]<<endl;
    }
    
    for(auto e:SE){
        G2[e.fi].push_back(e.se);
        //cout<<e.fi<<" "<<e.se<<endl;
    }
    
    string res=T;
    
    set<string> seen;
    
    while(1){
        memset(use,0,sizeof(use));
        
        //cout<<res<<endl;
        
        for(int i=0;i<si(res);i++){
            DFS2(cmp[i*2+(S[res[i]-'a']=='C')]);
            //cout<<cmp[i*2+(S[res[i]-'a']=='C')]<<" ";
        }
        //cout<<res<<endl;
        bool check=true;
        for(int i=0;i<N;i++){
            if(use[cmp[2*i]]&&use[cmp[2*i+1]]) check=false;
        }
        
        if(si(res)==0&&!check){
            cout<<-1<<endl;
            return 0;
        }
        
        if(!check){
            res.pop_back();
            continue;
        }
        
        bool same=true;
        for(int i=0;i<si(res);i++){
            if(T[i]<res[i]){
                same=false;
                break;
            }
        }
        
        if(same){
            if(res==T){
                cout<<res<<endl;
                return 0;
            }
            
            //cout<<res<<endl;
            
            vector<int> C(4,INF);
            for(int i=L-1;i>=0;i--){
                if(S[i]=='V'){
                    if(i>int(T[si(res)]-'a')){
                        C[0]=i;
                    }
                    if(i==int(T[si(res)]-'a')){
                        C[1]=i;
                    }
                }else{
                    if(i>int(T[si(res)]-'a')){
                        C[2]=i;
                    }
                    if(i==int(T[si(res)]-'a')){
                        C[3]=i;
                    }
                }
            }
            
            sort(all(C));
            
            //for(int a:C) cout<<a<<" ";
            //cout<<endl;
            
            for(int i=0;i<4;i++){
                if(C[i]==INF){
                    if(si(res)==0){
                        cout<<-1<<endl;
                        return 0;
                    }
                    res.pop_back();
                    break;
                }
                
                res+=char('a'+C[i]);
                if(seen.count(res)) res.pop_back();
                else{
                    seen.insert(res);
                    //cout<<res<<endl;
                    break;
                }
                
                if(i==3){
                    if(si(res)==0){
                        cout<<-1<<endl;
                        return 0;
                    }
                    res.pop_back();
                    break;
                }
            }
            
        }else{
            if(si(T)==si(res)){
                cout<<res<<endl;
                return 0;
            }
            vector<int> C(2,INF);
            for(int i=L-1;i>=0;i--){
                if(S[i]=='V'){
                    C[0]=i;
                }else{
                    C[1]=i;
                }
            }
            
            sort(all(C));
            
            for(int i=0;i<2;i++){
                if(C[i]==INF){
                    if(si(res)==0){
                        cout<<-1<<endl;
                        return 0;
                    }
                    res.pop_back();
                    break;
                }
                
                res+=char('a'+C[i]);
                if(seen.count(res)) res.pop_back();
                else{
                    seen.insert(res);
                    break;
                }
                
                if(i==1){
                    if(si(res)==0){
                        cout<<-1<<endl;
                        return 0;
                    }
                    res.pop_back();
                    break;
                }
            }
        }
    }
}