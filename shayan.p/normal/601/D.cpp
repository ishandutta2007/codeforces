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

const int maxn = 3e5 + 10, Max = maxn * 12;

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

int a[maxn], id[maxn];
string s;
int nxt[Max][26], SZ[Max], C = 1;
pii ans = {0,0};

vector<int> v[maxn];

int merge(vector<int> &vec){
    if(vec.empty())
	return C++;
    if(sz(vec) == 1)
	return vec[0];
    int ID = C++;
    for(int c = 0; c < 26; c++){
	vector<int> vec2;
	for(int u : vec)
	    if(nxt[u][c] != 0)
		vec2.PB( nxt[u][c] );
	if(!vec2.empty()){
	    int x = merge(vec2);
	    nxt[ID][c] = x;
	    SZ[ID]+= 1 + SZ[x];
	}
    }
    return ID;
}
void dfs(int u, int par = -1){
    vector<int> vec;
    for(int  y : v[u]){
	if(y == par)
	    continue;
	dfs(y, u);
	vec.PB(id[y]);
    }
    id[u] = C++;
    int x = merge(vec);
    SZ[id[u]] = SZ[x] + 1;
    nxt[id[u]][s[u-1]-'a'] = x;
    if(ans.F < a[u] + SZ[id[u]])
	ans = {a[u] + SZ[id[u]], 0};
    if(ans.F == a[u] + SZ[id[u]])
	ans.S++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
	cin >> a[i];
    cin >> s;
    for(int i = 0; i < n-1; i++){
	int a, b;
	cin >> a >> b;
	v[a].PB(b);
	v[b].PB(a);
    }
    dfs(1);
    return cout << ans.F << endl << ans.S << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")