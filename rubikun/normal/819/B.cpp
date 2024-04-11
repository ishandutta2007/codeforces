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
const int mod=998244353,MAX=2000005;
const ll INF=1LL<<60;

ll imo[MAX],cost[MAX],cnt[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i];
        P[i]--;
    }
    
    for(int i=0;i<N;i++){
        if(P[i]>=i){
            int s=P[i]-i,to=N-i;
            imo[s]+=i-P[i];
            imo[to]-=i-P[i];
            
            cnt[s]++;
            cnt[to]--;
        }else{
            int to=N-i,s=P[i]+N-i;
            imo[0]+=i-P[i];
            imo[to]-=i-P[i];
            
            cnt[0]++;
            cnt[to]--;
            
            imo[s]+=i-P[i]-N;
            imo[N]-=i-P[i]-N;
            
            cnt[s]++;
            cnt[N]--;
        }
    }
    
    for(int i=0;i<=N;i++){
        if(i) imo[i]+=imo[i-1];
        if(i) cnt[i]+=cnt[i-1];
        cost[i]+=imo[i];
        cost[i]+=cnt[i]*i;
    }
    
    pair<ll,int> ans=mp(INF,-1);
    for(int i=0;i<N;i++){
        //cout<<cost[i]<<"\n";
        chmin(ans,mp(cost[i],i));
    }
    
    cout<<ans.fi*2<<" "<<ans.se<<"\n";
}