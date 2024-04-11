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
    
    int N;cin>>N;
    vector<ll> V(N),rui(N),ma(N);
    ll sum=0;
    for(int i=0;i<N;i++){
        cin>>V[i];
        sum+=V[i];
        rui[i]=sum;
        ma[i]=(rui[i]+i)/(i+1);
        if(i) chmax(ma[i],ma[i-1]);
    }
    
    int Q;cin>>Q;
    while(Q--){
        ll x;cin>>x;
        int left=0,right=N+1;
        while(right-left>1){
            ll mid=(left+right)/2;
            bool f=true;
            f&=(ma[mid-1]<=x);
            f&=(mid*x>=sum);
            if(f) right=mid;
            else left=mid;
        }
        if(right==N+1) cout<<-1<<"\n";
        else cout<<right<<"\n";
    }
}