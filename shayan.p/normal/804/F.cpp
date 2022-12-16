#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator << (ostream &out, pair<A, B> x){
    out << "{ "<< x.F << ", " << x.S << "}";
    return out;
}
template<typename A, typename B> istream& operator >> (istream &in, pair<A, B> &x){
    in >> x.F >> x.S;
    return in;
}
template<typename A> ostream& operator << (ostream &out, vector<A> v){
    out << "[ ";
    for(int i = 0; i < sz(v); i++){
	out << v[i];
	if(i != sz(v)-1)
	    out<< ", ";
    }
    return out << " ]";
}

const int maxn = 5010, Max = 2e6 + 10, mod = 1e9 + 7;

vector<int> v[maxn], rv[maxn];
int arr[maxn];
bool mark[maxn];

vector<bool> vg;
vector<bool> str[maxn];
vector<bool> varr[maxn];
vector<int> inside[maxn];

void dfs(int u, int src){
    mark[u] = 1;
    int g = __gcd( sz(vg), sz(str[u]) );
    for(int i = 0; i < sz(vg); i++)
	vg[i %g]= vg[i] | vg[i % g];
    vg.resize(g);
    for(int i = 0; i < sz(str[u]); i++)
	vg[i %g]= str[u][i] | vg[i %g];
    inside[src].PB(u);
    for(int y : rv[u])
	if(mark[y] == 0)
	    dfs(y, src);
}

pii p[maxn];
int START[Max], END[Max];
int C[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    for(int i = 0; i < maxn; i++){
	C[i][0] = 1;
	for(int j = 1; j <= i; j++)
	    C[i][j] = (C[i-1][j-1] + C[i-1][j]) %mod;
    }
    
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
	string s;
	cin >> s;
	for(int j = 0; j < n; j++)
	    if(s[j] == '1')
		v[i].PB(j), rv[j].PB(i);
    }
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	string s;
	cin >> s;
	for(int j = 0; j < sz(s); j++)
	    str[i].PB(s[j] == '1');
    }
    iota(arr, arr+n, 0);
    sort(arr, arr+n, [&](int i, int j){ return sz(v[i]) > sz(v[j]); } );
    int N = 0;
    for(int i = 0; i < n; i++){
	if(mark[arr[i]])
	    continue;
	vg = str[ arr[i] ];
	dfs(arr[i], N);
	varr[N] = vg;
	N++;
    }    
    for(int i = 0; i < N-1; i++){
	int g = __gcd( sz(varr[i]), sz(varr[i+1]) );
	vector<bool> vv(g);
	for(int j = 0; j < sz(varr[i]); j++)
	    vv[j % g] = vv[j % g] | varr[i][j];
	for(int j = 0; j < sz(varr[i+1]); j++)
	    varr[i+1][j] = varr[i+1][j] | vv[j % g];	
    }
    for(int i = 0; i < n; i++){
	for(int j = 0; j < sz(str[i]); j++)
	    p[i].F += str[i][j];
    }
    for(int i = 0; i < N; i++){
	int num = 0;
	for(int x : varr[i])
	    num+= x;
	for(int u : inside[i])
	    p[u].S = num * (sz(str[u]) / sz(varr[i]));
    }
    for(int i = 0; i < n; i++){
	START[ p[i].F ]++;
	END[ p[i].S ]++;
    }
    int A = 0, B = 0, ans = 0;
    for(int i = Max-3; i >= 0; i--){
	if(START[i] == 0 && END[i] == 0)
	    continue;	
	B+= END[i];
	for(int j = max(int(0), A - (a-b)); j <= min(A, b); j++){
	    ans = ( 1ll * ans + 1ll * C[A][j] * (C[B][b-j] - C[B - END[i]][b-j]) ) %mod;
	}	
	A+= START[i];
	B-= START[i];
    }
    if(ans < 0)
	ans+= mod;
    return cout << ans << endl, 0;
}