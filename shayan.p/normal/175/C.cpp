// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

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

pii p[maxn];
ll lm[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> p[i].S >> p[i].F;
    }
    sort(p, p+n);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
	cin >> lm[i];
    }
    ll ans = 0, cnt = 0, F = 1;
    for(int i = 0; i < n; i++){
	ll num = p[i].S;
	if(F <= t)
	    num = min(num, lm[F]-cnt);
	ans+= F * p[i].F * num;
	cnt+= num;
	if(F <= t && cnt == lm[F])
	    F++;
	p[i].S-= num;
	if(p[i].S > 0)
	    --i;
    }
    return cout << ans << endl, 0;
}