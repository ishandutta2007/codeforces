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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<pair<int,int>,int>> E(M);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(a>b) swap(a,b);
        E[i]=mp(mp(a,b),c);
    }
    
    sort(all(E),[](auto a,auto b){
        return a.fi.se<b.fi.se;
    });
    
    vector<int> ans(N);
    
    for(int q=0;q<30;q++){
        vector<int> ng(N),must(N);
        for(int i=0;i<M;i++){
            int a=E[i].fi.fi,b=E[i].fi.se,c=E[i].se;
            if(c&(1<<q)){
                
            }else{
                ng[a]=true;
                ng[b]=true;
            }
        }
        for(int i=0;i<M;i++){
            int a=E[i].fi.fi,b=E[i].fi.se,c=E[i].se;
            if(c&(1<<q)){
                if(ng[a]) must[b]=true;
                if(ng[b]) must[a]=true;
            }else{
                
            }
        }
        for(int i=0;i<M;i++){
            int a=E[i].fi.fi,b=E[i].fi.se,c=E[i].se;
            if(c&(1<<q)){
                if(must[a]){
                    
                }else{
                    must[b]=true;
                }
            }else{
                
            }
        }
        
        for(int i=0;i<N;i++){
            if(must[i]) ans[i]|=(1<<q);
        }
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}