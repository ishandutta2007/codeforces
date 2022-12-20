// Never let them see you bleed...
// Shayan.P  2020-05-06

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 4e18;

ll a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    ll k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    ll l = -inf, r = inf;
    while(r-l > 1){
	ll mid = (l+r) / 2;
	ll cnt = 0;
	for(int i = 0; i < n; i++){
	    ll num = (a[i] - mid) / 3;
	    if(num >= 0){
		ll sq = sqrt(num);
		while(num < sq * (sq+1))
		    sq--;
		while(num >= sq * (sq+1))
		    sq++;		
		cnt+= min(sq, a[i]);
	    }		
	}
	if(cnt >= k)
	    l = mid;
	else
	    r = mid;	   
    }
    vector<int> pos;
    
    ll cnt = 0;
    for(int i = 0; i < n; i++){
	ll num = (a[i] - l) / 3;
	if(num >= 0){
	    ll sq = sqrt(num);
	    while(num < sq * (sq+1))
		sq--;
	    while(num >= sq * (sq+1))
		sq++;		
	    b[i] = min(sq, a[i]);
	    cnt+= b[i];
	    if( a[i]-l == 3ll * (sq-1) * (sq) && b[i] > 0)
		pos.PB(i);
	}
    }
    while(cnt > k){
	b[pos.back()]--;
	pos.pop_back();
	cnt--;
    }
    for(int i = 0; i < n; i++){
	cout << b[i] << " ";
    }
    return cout << endl, 0;
}