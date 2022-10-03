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
const int mod=1000000007,MAX=3005;
const ll INF=1LL<<60;

vector<ll> cost[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    ll ans=INF;
    vector<pair<int,ll>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].fi>>A[i].se;
        A[i].fi--;
        cost[A[i].fi].push_back(A[i].se);
    }
    
    for(int i=0;i<M;i++){
        sort(all(cost[i]));
        reverse(all(cost[i]));
    }
    
    for(int x=0;x<=(N-1)/2;x++){
        ll sum=0;
        int cnt=si(cost[0]);
        
        vector<ll> rem;
        
        for(int i=1;i<M;i++){
            for(int j=x;j<si(cost[i]);j++){
                cnt++;
                sum+=cost[i][j];
            }
            for(int j=0;j<min(x,si(cost[i]));j++) rem.push_back(cost[i][j]);
        }
        
        sort(all(rem));
        //reverse(all(rem));
        
        for(int j=0;j<(x+1)-cnt;j++) sum+=rem[j];
        
        chmin(ans,sum);
    }
    
    cout<<ans<<endl;
}