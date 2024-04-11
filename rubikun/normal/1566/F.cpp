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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        
        vector<pair<ll,ll>> S(M);
        for(int i=0;i<M;i++) cin>>S[i].fi>>S[i].se;
        sort(all(S));
        S.erase(unique(all(S)),S.end());
        sort(all(S),[](auto a,auto b){
            if(a.fi==b.fi) return a.se>b.se;
            return a.fi<b.fi;
        });
        
        vector<pair<ll,ll>> ST;
        for(auto e:S){
            while(si(ST)&&ST.back().se>=e.se) ST.pop_back();
            auto it=lower_bound(all(A),e.fi);
            if(it!=A.end()&&*it<=e.se) continue;
            ST.push_back(e);
        }
        S=ST;
        M=si(S);
        
        vector<int> wh(N);
        for(int i=0;i<N;i++){
            wh[i]=lower_bound(all(S),mp(A[i],A[i]))-S.begin();
        }
        
        for(int i=0;i<=M;i++) dp[i]=INF;
        dp[0]=0;
        for(int i=0;i<N;i++){
            if(i-1>=0&&i+1<N&&wh[i-1]==wh[i]&&wh[i]==wh[i+1]) continue;
            int m=wh[i];
            int l,r;
            if(i==0) l=0;
            else l=wh[i-1];
            if(i+1==N) r=M;
            else r=wh[i+1];
            
            ll mi=INF;
            for(int j=l;j<m;j++) chmin(mi,dp[j]+(A[i]-S[j].se)*2);
            chmin(mi,dp[m]);
            for(int j=m+1;j<=r;j++){
                chmin(dp[j],mi+S[j-1].fi-A[i]);
            }
            
            mi=INF;
            for(int j=l;j<m;j++) chmin(mi,dp[j]+(A[i]-S[j].se));
            chmin(mi,dp[m]);
            for(int j=m+1;j<=r;j++){
                chmin(dp[j],mi+(S[j-1].fi-A[i])*2);
            }
            
            for(int j=l;j<m;j++){
                chmin(dp[m],dp[j]+A[i]-S[j].se);
            }
        }
        
        cout<<dp[M]<<"\n";
        
        //for(auto e:S) cout<<e.fi<<" "<<e.se<<endl;
    }
}