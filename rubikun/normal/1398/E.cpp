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
const int mod=1000000007,MAX=205,INF=1<<30;

struct BIT{
    vector<ll> bit;
    int N;
    //1-indexed
    
    void init(int n_){
        N=n_;
        n_*=2;
        for(int i=30;i>=0;i--){
            if(n_&(1<<i)){
                n_=1<<i;
                n_++;
                break;
            }
        }
        bit.assign(n_,0);
    }
    
    ll sum(int i){
        ll s=0;
        while(i>0){
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }
    
    //st=sum(t)-sum(s-1)
    
    void add(int i,ll x){
        while(i<=N){
            bit[i]+=x;
            i+=i&-i;
        }
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    vector<pair<int,ll>> S(Q);
    map<ll,int> MA;
    for(int q=0;q<Q;q++){
        cin>>S[q].fi>>S[q].se;
        if(S[q].se>0) MA[-S[q].se]=1;
    }
    
    int id=1;
    
    for(auto &a:MA){
        a.se=id;
        id++;
    }
    
    BIT cnt,sum,Acnt,Asum,Bcnt,Bsum;
    cnt.init(id);
    sum.init(id);
    Acnt.init(id);
    Asum.init(id);
    Bcnt.init(id);
    Bsum.init(id);
    
    set<ll> sea,seb;
    
    for(int q=0;q<Q;q++){
        int t=S[q].fi;ll k=S[q].se;
        if(k>0){
            cnt.add(MA[-k],1);
            sum.add(MA[-k],k);
            
            if(t==0){
                Acnt.add(MA[-k],1);
                Asum.add(MA[-k],k);
                
                sea.insert(k);
            }else{
                Bcnt.add(MA[-k],1);
                Bsum.add(MA[-k],k);
                
                seb.insert(k);
            }
        }else{
            cnt.add(MA[k],-1);
            sum.add(MA[k],k);
            
            if(t==0){
                Acnt.add(MA[k],-1);
                Asum.add(MA[k],k);
                
                sea.erase(-k);
            }else{
                Bcnt.add(MA[k],-1);
                Bsum.add(MA[k],k);
                
                seb.erase(-k);
            }
        }
        
        int a=Acnt.sum(id),b=Bcnt.sum(id);
        if(b==0){
            cout<<Asum.sum(id)<<"\n";
        }else if(a==0){
            cout<<Bsum.sum(id)*2-*seb.begin()<<"\n";
        }else{
            int left=1,right=id;
            int can=Bcnt.sum(id);
            while(right-left>1){
                int mid=(left+right)/2;
                int c=cnt.sum(mid);
                if(c>can) right=mid;
                else left=mid;
            }
            ll ans=sum.sum(id)+sum.sum(left);
            if(Bcnt.sum(left)==can){
                ans-=*seb.begin();
                ans+=*sea.rbegin();
            }
            
            cout<<ans<<"\n";
        }
    }
}