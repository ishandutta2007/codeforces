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

ll solve(ll N){
    if(N==0) return 0LL;
    ll left=0,right=2000000000LL;
    while(right-left>1){
        ll mid=(left+right)/2;
        if(mid*(mid+2)<=N) left=mid;
        else right=mid;
    }
    ll res=left*3;
    ll k=right;
    if(right*right<=N) res++;
    if(right*(right+1)<=N) res++;
    if(right*(right+2)<=N) res++;
    
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll L,R;cin>>L>>R;
        cout<<solve(R)-solve(L-1)<<"\n";
    }
}