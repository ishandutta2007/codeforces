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
const int mod=1000000009,MAX=200005;
const ll INF=1LL<<60;

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
        vector<pair<pair<int,int>,pair<int,int>>> que;
        for(int i=0;i<N;i++){
            int t;cin>>t;
            int l,r;cin>>l>>r;
            que.push_back(mp(mp(l,1),mp(t,i)));
            que.push_back(mp(mp(r+1,-1),mp(t,i)));
        }
        
        sort(all(que));
        
        UF uf;uf.init(N);
        
        map<int,int> A,B;
        
        vector<pair<int,int>> mer;
        
        for(auto x:que){
            //cout<<x.fi.fi<<" "<<x.fi.se<<" "<<x.se.fi<<" "<<x.se.se<<" "<<si(A)<<" "<<si(B)<<endl;
            if(x.se.fi==0){
                if(si(B)){
                    mer.push_back(mp(x.se.se,(*B.begin()).fi));
                    auto l=B.begin(),r=B.begin();r++;
                    int sum=0;
                    while(r!=B.end()){
                        uf.unite((*l).fi,(*r).fi);
                        sum+=(*l).se;
                        l++;r++;
                    }
                    sum+=(*l).se;
                    int ro=uf.root((*l).fi);
                    B.clear();
                    B[ro]+=sum;
                }
                
                if(x.fi.se==1){
                    A[uf.root(x.se.se)]++;
                }else{
                    assert(A.count(uf.root(x.se.se)));
                    A[uf.root(x.se.se)]--;
                    //for(auto a:A) cout<<a.fi<<" "<<a.se<<endl;
                    if(A[uf.root(x.se.se)]==0){
                        auto it=A.find(uf.root(x.se.se));
                        A.erase(it);
                        //A.erase(uf.root(x.se.se));
                    }
                }
            }else{
                if(si(A)){
                    mer.push_back(mp(x.se.se,(*A.begin()).fi));
                    auto l=A.begin(),r=A.begin();r++;
                    int sum=0;
                    while(r!=A.end()){
                        uf.unite((*l).fi,(*r).fi);
                        sum+=(*l).se;
                        l++;r++;
                    }
                    sum+=(*l).se;
                    int ro=uf.root((*l).fi);
                    A.clear();
                    A[ro]+=sum;
                }
                
                if(x.fi.se==1){
                    B[uf.root(x.se.se)]++;
                }else{
                    assert(B.count(uf.root(x.se.se)));
                    B[uf.root(x.se.se)]--;
                    if(B[uf.root(x.se.se)]==0){
                        auto it=B.find(uf.root(x.se.se));
                        B.erase(it);
                        //A.erase(uf.root(x.se.se));
                    }
                }
            }
        }
        
        for(auto a:mer){
            uf.unite(a.fi,a.se);
        }
        
        int ans=0;
        for(int i=0;i<N;i++) if(uf.root(i)==i) ans++;
        
        cout<<ans<<"\n";
    }
}