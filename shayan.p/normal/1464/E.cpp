#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 3e5 + 10, mod = 998244353;

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;
}

vector<int> v[maxn];
int grundy[maxn], grundyc[maxn];
bool mark[maxn];

void dfs(int u){
    mark[u] = 1;
    vector<int> vec;
    for(int y : v[u]){
	if(!mark[y])
	    dfs(y);
	vec.PB(grundy[y]);
    }
    sort(vec.begin(), vec.end());
    vec.resize( unique(vec.begin(), vec.end()) - vec.begin() );
    grundy[u] = sz(vec);
    for(int i = 0; i < sz(vec); i++){
	if(vec[i] != i){
	    grundy[u] = i;
	    return;
	}
    }	
}

void txor(int *a,int tw,bool inv){
    for(int ln=1;(2*ln)<=tw;ln*=2){
	for(int l=0;l<tw;l+=ln+ln){
	    for(int i=0;i<ln;i++){
		int x=a[l+i],y=a[l+ln+i];
		a[l+i]=(x+y) % mod;
		a[l+ln+i]=(x-y) % mod;
	    }
	}
    }
    if(inv){
	for(int i=0;i<tw;i++)
	    a[i] = 1ll * a[i] * Pow(tw, mod-2) % mod;
    }
}

int p[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);	
    }
    for(int i = 1; i <= n; i++){
	if(!mark[i])
	    dfs(i);
    }

    for(int i = 1; i <= n; i++){
	grundyc[grundy[i]]++;
    }
    for(int i = 0; i <= n; i++){
	p[i] = 1ll * grundyc[i] * Pow(n+1, mod-2) % mod;
    }

    int Tw = 1;
    while(Tw < n)
	Tw*= 2;
    txor(p, Tw, 0);
    for(int i = 0; i < Tw; i++)
	p[i] = Pow(1ll * (1-p[i]) * (n+1) % mod, mod-2);
    txor(p, Tw, 1);
    int ans = (1-p[0]) % mod;
    if(ans < 0)
	ans+= mod;
    return cout << ans << endl, 0;
}