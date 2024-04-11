// Never let them see you bleed...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int P1 = 1e9 + 7, P2 = 1e9 + 9; // zarb bishtar az 2e18 beshe P haye dige?
const ll MOD = 1ll * P1 * P2;

template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[";
    for(T x : v)
	out << x << ", ";
    out << "]";
    return out;
}

int Pow(int a, int b, int md){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a % md)
	if(b&1)
	    ans = 1ll * ans * a % md;
    return ans;		
}

template<int mod> struct matrix{
    static const int maxn = 62;
    int a[maxn][2 * maxn], inv[maxn][maxn];
    void SWAP(int i, int j){
	for(int w = 0; w < 2 * maxn; w++)
	    swap(a[i][w], a[j][w]);
    }
    void MUL(int i, int x){
	for(int w = 0; w < 2 * maxn; w++)
	    a[i][w] = 1ll * a[i][w] * x % mod;
    }
    void MINUS(int i, int j, int x){
	for(int w = 0; w < 2 * maxn; w++)
	    a[i][w] = (1ll * a[i][w] - 1ll * a[j][w] * x) % mod;
    }
    void toInverse(int n){
	for(int i = 0; i < n; i++)
	    a[i][n+i] = 1;
	for(int i = 0; i < n; i++){
	    int id = -1;
	    for(int j = i; j < n; j++){
		if(a[j][i] != 0)
		    id = j;
	    }
	    assert(id != -1);
	    SWAP(i, id);
	    MUL(i, Pow(a[i][i], mod-2, mod));
	    for(int j = 0; j < n; j++){
		if(j != i && a[j][i] != 0)
		    MINUS(j, i, a[j][i]);
	    }
	}
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < n; j++){
		inv[i][j] = a[i][j+n];
	    }
	}
    }
    vector<ll> solve(vector<ll> vec){
	int n = sz(vec);
	vector<ll> ans(n);
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < n; j++){
		ans[i] = (1ll * ans[i] + 1ll * inv[i][j] * vec[j]) % mod;
	    }
	}
	return ans;
    }
};
matrix<P1> m1;
matrix<P2> m2;

ll eval(int a, int b){
    a%=P1, b%=P2;
    if(a < 0)
	a+= P1;
    if(b < 0)
	b+= P2;
    int k = 1ll * (b-a) * Pow(P1, P2-2, P2) % P2;
    if(k < 0)
	k+= P2;
    return 1ll * k * P1 + a;
}

const int maxn = 60;

int a[maxn][2], f[maxn];
ll num[maxn];

ll solve(){
    int u;
    string s;
    cin >> u >> s;
    --u;
    int n = sz(s) + 1;
    ll msk = 0;
    for(int i = 0; i < n-1; i++)
	msk|= (1ll * (s[i] == 'R')) << i;
    vector<ll> vec(n-1);
    vec[0]++;
    vec[u]--;
    for(int i = 0; i < n-1; i++){
	if(bit(msk, i)){
	    vec[i]--;
	    if(a[i][1] < n-1)
		vec[ a[i][1] ]++;
	}	
    }
    vector<ll> v1 = m1.solve(vec), v2 = m2.solve(vec), ans(n-1);
    ll ANS = 0;
    for(int i = 0; i < n-1; i++){
	ans[i] = eval(v1[i], v2[i]);
	ANS+= ans[i] * 2;
	if(bit(msk, i))
	    ANS++;
	if(ANS >= MOD)
	    return -1;
    }
    memset(num, 0, sizeof num);
    for(int i = 0; i < n-1; i++){
	num[ a[i][0] ]-= ans[i];
	num[ a[i][1] ]-= ans[i];
	num[i]+= ans[i] * 2;
	if(bit(msk, i)){
	    num[i]++;
	    num[a[i][1]]--;
	}	    
    }
    num[0]--;
    num[u]++;
	
    for(int i = 0; i < n; i++){ // not n-1 !!!
	if(num[i] != 0)
	    return -1;
    }

    memset(f, -1, sizeof f);
    for(int i = 0; i < n-1; i++){
	if(i != u && (ans[i] + bit(msk, i)) > 0)
	    f[i] = a[i][bit(msk, i)];		
    }

    for(int i = 0; i < n-1; i++){
	int tmp = i;
	for(int j = 0; tmp != -1 && j < n; j++){
	    tmp = f[tmp];
	}
	if(tmp != -1)
	    return -1;
    }
    return ANS;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
	m1.a[i][i] = m2.a[i][i] = 2;
    }
    for(int i = 0; i < n-1; i++){
	cin >> a[i][0] >> a[i][1];
	--a[i][0], --a[i][1];
	m1.a[ a[i][0] ][i]--;
	m2.a[ a[i][0] ][i]--;
	m1.a[ a[i][1] ][i]--;
	m2.a[ a[i][1] ][i]--;
    }
    m1.toInverse(n-1);
    m2.toInverse(n-1);
		 
    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
    return 0;
}