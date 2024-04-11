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
const int mod=1000000007,MAX=1000005,INF=1<<30;
ll rui3[MAX];

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

void add(int &need,int one,int two){
    int a=min(one,two);
    need+=a;
    need+=(one-a)/3*2;
    need+=(two-a)/3*3;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    rui3[0]=1;
    for(int i=1;i<MAX;i++) rui3[i]=rui3[i-1]*3%mod;
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        UF uf;
        uf.init(N);
        for(int i=0;i<N;i++){
            int a;cin>>a;
            a--;
            uf.unite(i,a);
        }
        
        int need=0;
        bool yonn=false;
        
        vector<int> cnt(3);
        for(int i=0;i<N;i++){
            if(uf.root(i)==i){
                cnt[uf.size[i]%3]++;
                if(uf.size[i]>=3) need+=(uf.size[i]-1)/3;
                if(uf.size[i]>=4&&uf.size[i]%3==1) yonn=true;
            }
        }
        
        ll ans=1;
        if(N%3==0) ans=rui3[N/3];
        if(N%3==1) ans=rui3[(N-4)/3]*4%mod;
        if(N%3==2) ans=rui3[(N-2)/3]*2%mod;
        
        if(N%3==0){
            add(need,cnt[1],cnt[2]);
        }
        
        if(N%3==1){
            int need1=0,need2=0;
            if(yonn){
                need1--;
                add(need1,cnt[1]-1,cnt[2]);
            }else{
                if(cnt[1]&&cnt[0]){
                    need1++;
                    add(need1,cnt[1]-1,cnt[2]);
                }else{
                    need1=INF;
                }
            }
            
            if(cnt[2]==0){
                if(cnt[1]>=4){
                    need2+=2;
                    need2+=(cnt[1]-4)/3*2;
                }else{
                    need2=INF;
                }
            }else if(cnt[2]==1){
                need2++;
                need2+=(cnt[1]-2)/3*2;
            }else{
                add(need2,cnt[1],cnt[2]-2);
            }
            
            need+=min(need1,need2);
        }
        
        if(N%3==2){
            if(cnt[2]==0){
                need++;
                need+=(cnt[1]-2)/3*2;
            }else{
                cnt[2]--;
                add(need,cnt[1],cnt[2]);
            }
        }
        
        cout<<ans<<" "<<need<<"\n";
    }
}