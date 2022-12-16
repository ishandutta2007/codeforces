// They can't break me, as long as I know who I am...

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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

vector<int> dv[maxn];
vector<int> tdo[maxn];
int N;
ll ANS;
int cnt[maxn], mo[maxn];
bool isp[maxn];

void init(int _N){
    N = _N;
    fill(cnt + 1, cnt + N + 1, 0);
    ANS = 0;
}
void add(int x, int k){
    for(int y : dv[x]){
	ANS -= 1ll * cnt[y] * cnt[y] * mo[y];
	cnt[y]+= k;
	ANS += 1ll * cnt[y] * cnt[y] * mo[y];
    }
}

int inp[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 1; i < maxn; i++)
	for(int j = i; j < maxn; j+=i)
	    dv[j].PB(i);
    fill(mo, mo + maxn, 1);
    for(int i = 2; i < maxn; i++){
	if(isp[i] == 0){
	    for(int j = i; j < maxn; j+=i){
		mo[j]*=-1;
		if((j / i) % i == 0)
		    mo[j] = 0;
		isp[j] = 1;
	    }
	}
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
	cin >> inp[i];
    sort(inp, inp + n);
    n = unique(inp, inp + n) - inp;
    for(int i = 0; i < n; i++){
	for(int x : dv[ inp[i] ])
	    tdo[x].PB(inp[i] / x);
    }

    ll ans = 0;
    for(int i = 1; i < maxn; i++){
	if(tdo[i].empty())
	    continue;
	init( maxn / i );
	sort(tdo[i].begin(), tdo[i].end(), greater<int>() );
	if(tdo[i].back() == 1){
	    ans = max(ans, 1ll * tdo[i][0] * i);
	    tdo[i].pop_back();
	}
	vector<int> vec;
	for(int x : tdo[i]){
	    add(x, 1);
	    if(ANS){
		int lst;
		while(ANS){
		    lst = vec.back();
		    add(vec.back(), -1);
		    vec.pop_back();
		}
		add(x, -1);
		ans = max(ans, 1ll * lst * x * i);
	    }
	    else{
		vec.PB(x);
	    }
	}
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")