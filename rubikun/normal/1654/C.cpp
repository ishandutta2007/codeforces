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

multiset<ll> SE;
ll sum=0;
bool ans=true;

void solve(ll x){
    if(!ans) return;
    if(SE.find(x)!=SE.end()){
        auto it=SE.lower_bound(x);
        SE.erase(it);
        return;
    }else if(x==1){
        ans=false;
        return;
    }else{
        solve(x/2);
        solve((x+1)/2);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        SE.clear();
        sum=0;
        ans=true;
        for(int i=0;i<N;i++){
            ll x;cin>>x;
            SE.insert(x);
            sum+=x;
        }
        
        solve(sum);
        
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}