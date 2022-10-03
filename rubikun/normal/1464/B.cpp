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

ll cnt0[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    string T=S;
    
    int N=si(T);
    
    for(int i=0;i<N;i++) if(T[i]=='?') T[i]='1';
    
    for(int i=1;i<=N;i++){
        cnt0[i]+=cnt0[i-1];
        if(T[i-1]=='0') cnt0[i]++;
    }
    
    ll ans=0;
    
    ll x,y;cin>>x>>y;
    
    vector<ll> diff;
    
    for(int i=0;i<N;i++){
        if(T[i]=='0'){
            ans+=(ll(i)-cnt0[i])*y;
            ans+=(ll(N)-1-i-(cnt0[N]-cnt0[i+1]))*x;
        }
        
        if(S[i]=='?') diff.push_back(cnt0[i]*x+(cnt0[N]-cnt0[i+1])*y-(ll(i)-cnt0[i])*y-(ll(N)-1-i-(cnt0[N]-cnt0[i+1]))*x);
    }
    
    sort(all(diff));
    reverse(all(diff));
    
    ll sum=0,ma=0;
    
    for(int i=0;i<si(diff);i++){
        sum+=diff[i];
        sum+=ll(i)*(x+y);
        chmax(ma,sum);
        
        //cout<<diff[i]<<endl;
    }
    
    //cout<<ans<<endl;
    cout<<ans-ma<<endl;
}