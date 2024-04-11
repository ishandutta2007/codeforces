#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,M;cin>>N>>M;
        vector<pair<ll,ll>> que(N);
        vector<ll> use;
        for(int i=0;i<N;i++){
            cin>>que[i].fi>>que[i].se;
            use.push_back(que[i].fi);
            use.push_back(que[i].fi-que[i].se);
            use.push_back(que[i].fi+que[i].se);
        }
        use.push_back(-INF);
        use.push_back(INF);
        sort(all(use));
        use.erase(unique(all(use)),use.end());
        
        int K=si(use);
        
        vector<ll> imo1(K+1),imo2(K+1);
        
        for(int i=0;i<N;i++){
            ll a=que[i].fi,b=que[i].se;
            auto l=lower_bound(all(use),a-b)-use.begin(),m=lower_bound(all(use),a)-use.begin(),r=lower_bound(all(use),a+b)-use.begin();
            imo1[l]+=-(a-b);
            imo1[m+1]-=-(a-b);
            imo2[l]++;
            imo2[m+1]--;
            
            
            imo1[m+1]+=(a+b);
            imo1[r+1]-=(a+b);
            imo2[m+1]--;
            imo2[r+1]++;
        }
        
        for(int i=1;i<=K;i++){
            imo1[i]+=imo1[i-1];
            imo2[i]+=imo2[i-1];
        }
        
        vector<pair<ll,pair<ll,ll>>> need;
        vector<ll> lma,rma;
        for(int i=1;i<=K;i++){
            //cout<<imo1[i]+imo2[i]*use[i]<<" ";
            ll x=use[i];
            ll y=imo1[i]+imo2[i]*use[i]-M;
            if(y>0){
                need.push_back(mp(x,mp(y-x,x+y)));
                lma.push_back(y-x);
                rma.push_back(x+y);
            }else{
                need.push_back(mp(x,mp(-INF,-INF)));
                lma.push_back(-INF);
                rma.push_back(-INF);
            }
        }
        
        for(int i=1;i<si(lma);i++) chmax(lma[i],lma[i-1]);
        for(int i=si(rma)-2;i>=0;i--) chmax(rma[i],rma[i+1]);
        
        if(si(need)==0){
            for(int i=0;i<N;i++) cout<<'1';
            cout<<"\n";
            continue;
        }
        
        for(int i=0;i<N;i++){
            auto it=lower_bound(all(need),mp(que[i].fi,mp(0LL,0LL)))-need.begin();
            ll a=que[i].fi,b=que[i].se;
            bool f=true;
            f&=(b-a>=lma[it]);
            f&=(a+b>=rma[it]);
            if(f) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
        
        //cout<<endl;
    }
}