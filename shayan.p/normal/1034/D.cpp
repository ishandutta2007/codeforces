// So when you feel like hope is gone, Look inside you and be strong, And you'll finally see the truth, That a hero lies in you ... 
 
#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 3e5 + 10, Big = 1e9 + 10;

pii p[maxn];
int arr[2 * maxn], n, C;
int pt[maxn];

vector<pii> tdo[maxn];

void prep(){
    map<pii, int> mp;
    for(int i = 0; i < n; i++){
	auto it = mp.upper_bound((pii){p[i].F, -1});
	if(it != mp.begin())
	    --it;
	if(it != mp.end() && (it->F.S <= p[i].F))
	    ++it;
	
	while(it != mp.end() && it->F.F < p[i].S){
	    auto sg = *it;
	    it = next(it);
	    mp.erase(prev(it));
	    if(sg.F.F <= p[i].F && p[i].S <= sg.F.S){
		tdo[i].PB({sg.S, -arr[ p[i].S ] + arr[ p[i].F ]});
		if(sg.F.F != p[i].F)
		    mp[{sg.F.F, p[i].F}] = sg.S;
		if(sg.F.S != p[i].S)
		    mp[{p[i].S, sg.F.S}] = sg.S;
	    }
	    else if(p[i].F <= sg.F.F && sg.F.S <= p[i].S){
		tdo[i].PB({sg.S, -arr[ sg.F.S ] + arr[ sg.F.F ]});
	    }
	    else if(sg.F.S <= p[i].S){
		tdo[i].PB({sg.S, -arr[ sg.F.S ] + arr[ p[i].F ]});
		mp[{sg.F.F, p[i].F}] = sg.S;
	    }
	    else{
		tdo[i].PB({sg.S, -arr[ p[i].S ] + arr[ sg.F.F ]});
		mp[{p[i].S, sg.F.S}] = sg.S;
	    }	    
	}
	tdo[i].PB({i, arr[ p[i].S ] - arr[ p[i].F ]});
	mp[{p[i].F, p[i].S}] = i;
    }
}

int who[maxn];
ll ANS;

ll calc(int x){// tedad oonaii ke value az x bishtar mosavi e
    memset(who, 0, sizeof who);
    int l = 0;
    ll ans = 0;
    ll sum = 0, tot = 0, sum2 = 0;
    ANS = 0;
    for(int r = 0; r < n; r++){
	for(pii pp : tdo[r]){
	    who[pp.F]+= pp.S;
	    if(pp.F >= l)
		sum+= pp.S, sum2+= 1ll * (pp.F+1) * pp.S;
	    tot+= 1ll * (pp.F+1) * pp.S;
	}
	while(sum >= x){
	    sum-= who[l];
	    sum2-= 1ll * (l+1) * who[l];
	    l++;
	}	
	pt[r] = l;
	ans+= pt[r];
	ANS+= tot - sum2 + 1ll * l * sum;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin >> n;
    ll k;
    cin >> k;
    for(int i = 0; i < n; i++){
	cin >> p[i].F >> p[i].S;
	arr[C++] = p[i].F;
	arr[C++] = p[i].S;
    }
    sort(arr, arr+C);
    C = unique(arr, arr+C) - arr;
    for(int i = 0; i < n; i++){
	p[i].F = lower_bound(arr, arr+C, p[i].F) - arr;
	p[i].S = lower_bound(arr, arr+C, p[i].S) - arr;
    }

    prep();
    
    int l = 0, r = Big;
    while(r-l > 1){
	int mid = (l+r) >> 1;
	if(calc(mid) >= k)
	    l = mid;
	else
	    r = mid;
    }
    ll num = calc(r);
    return cout << ANS + 1ll * (k - num) * l << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")