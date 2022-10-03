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

int f(pair<int,int> a,pair<int,int> b){
    if(a.fi>a.se) swap(a.fi,a.se);
    if(b.fi>b.se) swap(b.fi,b.se);
    
    if(a==b) return -1;
    if(a.fi==b.fi) return a.fi;
    if(a.fi==b.se) return a.fi;
    if(a.se==b.fi) return a.se;
    if(a.se==b.se) return a.se;
    return 0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> A(N),B(M);
    vector<set<int>> C(N),D(M);
    for(int i=0;i<N;i++) cin>>A[i].fi>>A[i].se;
    for(int i=0;i<M;i++) cin>>B[i].fi>>B[i].se;
    
    set<int> ans;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int x=f(A[i],B[j]);
            if(x>=1){
                ans.insert(x);
                C[i].insert(x);
                D[j].insert(x);
            }
        }
    }
    
    if(si(ans)==1){
        cout<<*ans.begin()<<endl;
        return 0;
    }
    
    bool ok=true;
    
    for(int i=0;i<N;i++) if(si(C[i])>=2) ok=false;
    for(int i=0;i<M;i++) if(si(D[i])>=2) ok=false;
    
    if(ok) cout<<0<<endl;
    else cout<<-1<<endl;
}