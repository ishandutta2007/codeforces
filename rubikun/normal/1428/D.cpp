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
const int mod=1000000007,MAX=100005;
const int INF=1<<30;
//const ll INF=1LL<<60;

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

vector<int> wh[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),to(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    UF uf;
    uf.init(N);
    
    vector<stack<int>> ST(4);
    
    for(int i=N-1;i>=0;i--){
        if(A[i]==0) continue;
        
        if(A[i]==1) ST[1].push(i);
        else if(A[i]==2){
            if(ST[1].empty()){
                cout<<-1<<"\n";
                return 0;
            }
            ST[2].push(i);
            to[i]=ST[1].top();
            uf.unite(i,ST[1].top());
            ST[1].pop();
        }else{
            if(!ST[3].empty()){
                to[i]=ST[3].top();
                uf.unite(i,ST[3].top());
            }else if(!ST[2].empty()){
                to[i]=ST[2].top();
                uf.unite(i,ST[2].top());
                ST[2].pop();
            }else if(!ST[1].empty()){
                to[i]=ST[1].top();
                uf.unite(i,ST[1].top());
                ST[1].pop();
            }else{
                cout<<-1<<"\n";
                return 0;
            }
            
            ST[3].push(i);
        }
    }
    
    for(int i=0;i<N;i++){
        if(A[i]==0) continue;
        
        wh[uf.root(i)].push_back(i);
    }
    
    vector<pair<int,int>> ans;
    
    int t=0;
    
    for(int i=0;i<N;i++){
        if(si(wh[i])==0) continue;
        
        int cnt=0;
        for(int a:wh[i]) if(A[a]==3) cnt++;
        
        if(cnt==0){
            if(si(wh[i])==1) ans.push_back(mp(wh[i][0],t));
            else{
                ans.push_back(mp(wh[i][0],t));
                ans.push_back(mp(wh[i][1],t));
            }
            t++;
        }else{
            for(int j=0;j<si(wh[i]);j++){
                int a=wh[i][j];
                if(A[a]>=2){
                    ans.push_back(mp(wh[i][j],t));
                    ans.push_back(mp(wh[i][j+1],t));
                    t++;
                }else{
                    if(A[wh[i][j-1]]==3){
                        ans.push_back(mp(wh[i][j],t));
                        t++;
                    }
                }
            }
        }
    }
    
    cout<<si(ans)<<endl;
    
    for(auto x:ans) cout<<x.se+1<<" "<<x.fi+1<<"\n";
}