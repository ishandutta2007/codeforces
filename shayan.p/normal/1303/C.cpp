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

const int maxn = 1e5 + 10, mod = 1e9 + 7;
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

vector<int> v[27];
bool mark[27];
int NUM, NUM2;
string ans;

void dfs(int u){
    NUM++;
    NUM2+= sz(v[u]);
    mark[u] = 1;
    for(int y : v[u]){
	if(mark[y] == 0)
	    dfs(y);
    }
}
void dfs2(int u){
    ans+= 'a' + u;
    mark[u] = 1;
    for(int y : v[u])
	if(mark[y] == 0)
	    dfs2(y);
}

bool ask(string s){
    set<pii> st;
    for(int i = 0; i < sz(s)-1; i++){
	int a = s[i] - 'a', b = s[i+1] - 'a';
	if(a == b)
	    return 0;
	if(a > b)
	    swap(a, b);
	st.insert({a, b});
    }
    for(int i = 0; i < 26; i++){
	v[i].clear();
    }	
    for(pii p : st){
	v[p.F].PB(p.S);
	v[p.S].PB(p.F);
    }
    for(int i = 0; i < 26; i++){
	if( sz(v[i]) > 2 )
	    return 0;
    }
    memset(mark, 0, sizeof mark);
    for(int i = 0; i < 26; i++){
	if(mark[i] == 0){
	    NUM = 0, NUM2 = 0;
	    dfs(i);
	    if(2 * NUM - 2 != NUM2)
		return 0;
	}
    }
    ans = "";
    memset(mark, 0, sizeof mark);
    for(int i = 0; i < 26; i++){
	if(mark[i] == 0 && sz(v[i]) < 2)
	    dfs2(i);		
    }
    return 1;   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	string s;
	cin >> s;
	cout << (ask(s) ? "YES\n" + ans + "\n" : "NO\n");
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")