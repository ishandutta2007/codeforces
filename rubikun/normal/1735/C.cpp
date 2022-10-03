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

//Union Find


struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        string S;cin>>S;
        vector<int> nex(26,-1),used(26);
        
        UF uf;uf.init(26);
        
        string ans;
        
        for(char c:S){
            if(nex[c-'a']!=-1){
                ans+=char('a'+nex[c-'a']);
            }else{
                for(int i=0;i<26;i++){
                    if(i==(int)(c-'a')) continue;
                    if(used[i]) continue;
                    int a=uf.size[uf.root(c-'a')],b=uf.size[uf.root(i)];
                    if(uf.check(c-'a',i)){
                        if(a==26){
                            nex[c-'a']=i;
                            ans+=char('a'+i);
                            used[i]=true;
                            uf.unite(c-'a',i);
                            break;
                        }
                    }else{
                        nex[c-'a']=i;
                        ans+=char('a'+i);
                        used[i]=true;
                        uf.unite(c-'a',i);
                        break;
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}