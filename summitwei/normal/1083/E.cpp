#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005

struct Line{
    ll m;
    ll c;
    
    ll eval(ll x){
        return m*x+c;
    }
    
    ld inter(Line o){
        return (ld)(c-o.c)/(o.m-m);
    }
};

int n;
pair<pll, ll> ree[MN];
Line dp[MN];

deque<Line> d;
Line secondb(){
    Line top = d.back();
    d.pop_back();
    Line ans = d.back();
    d.push_back(top);
    return ans;
}
Line secondf(){
    Line top = d.front();
    d.pop_front();
    Line ans = d.front();
    d.push_front(top);
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    FOR(i, 1, n){
        cin >> ree[i].f.f >> ree[i].f.s >> ree[i].s;
    }
    
    sort(ree+1, ree+n+1);
    
    dp[0].m = 0;
    dp[0].c = 0;
    d.push_front(dp[0]);
    ll ans = 0;
    FOR(i, 1, n){
        dp[i].m = -ree[i].f.f;
        
        while(d.size() >= 2 && d.back().eval(ree[i].f.s) <= secondb().eval(ree[i].f.s)) d.pop_back();
        
        dp[i].c = d.back().eval(ree[i].f.s) + ree[i].f.f*ree[i].f.s-ree[i].s;
        
        ans = max(ans, dp[i].c);
        
        while(d.size() >= 2 && dp[i].inter(d.front()) >= d.front().inter(secondf())) d.pop_front();
        d.push_front(dp[i]);
    }
    
    cout << ans << "\n";
    
    return 0;
}