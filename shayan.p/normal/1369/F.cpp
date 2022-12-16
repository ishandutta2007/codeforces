// Never let them see you bleed...
// Shayan.P  2020-06-30

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

bool solve(ll s, ll e, bool aft){ // after: 1 W // 0 L
    if(s > e)
	return aft;
    if(aft){
	if(e & 1)
	    return !(s&1);
	if(s > (e/2))
	    return s&1;
	ll lst = ((e/2) + 1 + (((e/2)+1)&1)) / 2;
	if(s >= lst)
	    return 1;
	return solve(s, lst-1, 1);
    }
    else{
	if(s > (e/2))
	    return 1;
	return solve(s, e/2, 1);
    }
}

pii p[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	ll a, b;
	cin >> a >> b;
	p[i] = {solve(a, b, 0), solve(a, b, 1)};
    }
    for(int i = n-2; i >= 0; i--){
	p[i] = { (p[i].F && p[i+1].F) || (p[i].S && !p[i+1].F), (p[i].F && p[i+1].S) || (p[i].S && !p[i+1].S) };
    }
    return cout << p[0].S << " " << p[0].F << "\n", 0;
}