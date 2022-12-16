// Oh damn! Suddenly you're free to fly...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 3e5 + 10, mod = 998244353, inf = 1e9 + 10;

vector<int> ADD[maxn], ERA[maxn];
int cof[50];
pii seg[maxn];
set<int> super;
vector<pii> ed;

int fac[maxn], ifac[maxn];

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;
}
int C(int n, int k){
    if(n < k || k < 0)
	return 0;
    return 1ll * fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}

int recover[22][50];
int pr[maxn];

int fnd(int u){
    return pr[u] < 0 ? u : pr[u] = fnd(pr[u]);
}
void mrg(int a, int b){
    if( (a = fnd(a)) == (b = fnd(b)) )
	return;
    if(pr[a] > pr[b])
	swap(a, b);
    pr[a]+= pr[b];
    pr[b] = a;
}
void go(int pos, int c, int cnt = 0, int h = 0){
    int lock = 0, counter = 0;
    for(int x : super)
	recover[h][counter] = pr[x], counter++, lock+= pr[x] != -1;
    if(pos == sz(ed)){
	cof[lock]+= cnt & 1 ? -1 : 1;
	return;
    }
    go(pos + 1, c, cnt, h+1);
    if(seg[ed[pos].F].F <= c && c <= seg[ed[pos].F].S && seg[ed[pos].S].F <= c && c <= seg[ed[pos].S].S){
	mrg(ed[pos].F, ed[pos].S);
	go(pos + 1, c, cnt + 1, h + 1);
	counter = 0;
	for(int x : super)
	    pr[x] = recover[h][counter], counter++;
    }
}
void recalc_cof(int c){
    memset(cof, 0, sizeof cof);
    for(int x : super)
	pr[x] = -1;
    go(0, c);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll * fac[i-1] * i % mod;
    ifac[maxn-1] = Pow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--)
	ifac[i] = 1ll * ifac[i+1] * (i+1) % mod;
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
	int l, r;
	cin >> l >> r;
	ADD[l].PB(i);
	ERA[r+1].PB(i);
	seg[i] = {l, r};
    }
    for(int i = 1; i <= m; i++){
	int a, b;
	cin >> a >> b;
	super.insert(a), super.insert(b);
	ed.PB({a, b});
    }

    int ans = 0;
    
    cof[0] = 1;
    int out = 0;
    for(int i = 1; i <= n; i++){
	bool is = 0;
	for(int x : ADD[i]){
	    if(super.count(x))
		is = 1;
	    out++;
	}
	for(int x : ERA[i]){
	    if(super.count(x))
		is = 1;
	    out--;
	}
	if(is)
	    recalc_cof(i);
	for(int j = 0; j <= 40; j++) // 40
	    ans = (1ll * ans + 1ll * cof[j] * C(out - j, i - j)) % mod;
    }
    if(ans < 0)
	ans+= mod;
    return cout << ans << endl, 0;    
}