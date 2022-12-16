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

const int maxn = 2e5 + 10, mod = 1e9 + 7, cnst = 1e8;
const ll inf = 1e18;

template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> p){
    out << "{ " << p.F << ", " << p.S <<" }";
    return out;
}
template<typename T> ostream& operator << (ostream& out, vector<T> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out << " ,";
    }
    out << " ]";
    return out;
}

int cnt[maxn];
int hsh[2][maxn], hsh2[2][maxn];
int pw[maxn], pw2[maxn], P, P2;

int isp(int x){
    for(int i = 2; i*i <= x; i++)
	if(x % i == 0)
	    return 0;
    return 1;
}

bool solve(int a, int b, int len){
    if(cnt[a] - cnt[a+len] != cnt[b] - cnt[b+len])
	return 0;
    int CNT = cnt[a] - cnt[a+len];
    int A = (1ll * hsh[0][a] - 1ll * pw[CNT] * hsh[len&1][a+len]) % mod;
    int B = (1ll * hsh[0][b] - 1ll * pw[CNT] * hsh[len&1][b+len]) % mod;
    int C = (1ll * hsh2[0][a] - 1ll * pw2[CNT] * hsh2[len&1][a+len]) % mod;
    int D = (1ll * hsh2[0][b] - 1ll * pw2[CNT] * hsh2[len&1][b+len]) % mod;
    if(A < 0)
	A+= mod;
    if(B < 0)
	B+= mod;
    if(C < 0)
	C+= mod;
    if(D < 0)
	D+= mod;
    return A == B && C == D;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    srand(time(0));
    P = cnst + (rand() % cnst);
    while(isp(P) == 0)
	P++;
    P2 = cnst + cnst + cnst + (rand() % (cnst));
    while(isp(P2) == 0)
	P2++;
    
    pw[0] = 1;
    for(int i = 1; i < maxn; i++)
	pw[i] = 1ll * P * pw[i-1] % mod;
    pw2[0] = 1;
    for(int i = 1; i < maxn; i++)
	pw2[i] = 1ll * P2 * pw2[i-1] % mod;
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = n-1; i >= 0; i--)
	cnt[i] = (s[i]=='0') + cnt[i+1];
    for(int i = n-1; i >= 0; i--){
	if(s[i] == '0')
	    hsh[0][i] = (1ll * P * hsh[1][i+1] + 2) % mod,  hsh[1][i] = (1ll * P * hsh[0][i+1] + 1) % mod;
	else
	    hsh[0][i] = hsh[1][i+1], hsh[1][i] = hsh[0][i+1];
	if(s[i] == '0')
	    hsh2[0][i] = (1ll * P2 * hsh2[1][i+1] + 2) % mod,  hsh2[1][i] = (1ll * P2 * hsh2[0][i+1] + 1) % mod;
	else
	    hsh2[0][i] = hsh2[1][i+1], hsh2[1][i] = hsh2[0][i+1];
    }
    int q;
    cin >> q;
    while(q--){
	int a, b, len;
	cin >> a >> b >> len;
	--a, --b;
	cout << (solve(a, b, len) ? "Yes\n" : "No\n");
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")