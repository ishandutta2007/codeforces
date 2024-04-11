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

const int maxn = 1e6 + 10, mod = 1e9 + 7;
const int inf = 1e9;

int nxt[maxn][26];
int f[maxn], fb[maxn], ln[maxn], df[maxn], dpv[maxn], C;
int str[maxn], n;
int lst;

void mkay(int &a, int b){
    a = (a + b) %mod;
}
int loop(int tmp){
    while(tmp != -1 && str[ n - ln[tmp] -1 ] != str[n] )
	tmp = f[tmp];
    return tmp;
}
void add_char(char ch){
    int c = ch - 'a';
    str[++n] = c;
    lst = loop(lst);
    if( lst == -1){
	lst = 0;
	return;
    }
    if( nxt[lst][c] == 0 ){
	nxt[lst][c] = ++C;
	if( f[lst] == -1 || loop( f[lst] ) == -1 )
	    f[C] = 0;
	else
	    f[C] = nxt[ loop( f[lst] ) ][ c ];
	ln[C] = ln[lst] + 2;
	df[C] = ln[C] - ln[ f[C] ];
	fb[C] = df[C] == df[ f[C] ] ? fb[ f[C] ] : f[C];
    }
    lst = nxt[lst][c];
}



int dp[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    str[0] = -1;
    f[0] = -1;
    df[0] = -1;
    
    string ss, s; cin>>ss;
    for(int i = 0; 2 * i < sz(ss); i++){
	s+= ss[i];
	s+= ss[sz(ss)-1-i];
    }
    
    dp[0] = 1;
    for(int i = 1; i <= sz(s); i++){
	add_char( s[i-1] );
	dp[i] = 0;
	if(i & 1)
	    continue;
	for(int vert = lst; vert != 0; vert = fb[vert]){
	    int x = dp[ i - ln[ fb[ vert ] ] - df[vert] ];
	    if( df[vert] == df[ f[vert] ] )
		mkay(x, dpv[ f[vert] ] );
	    dpv[ vert ] = x;
	    mkay( dp[i], x );
	}
    }
    return cout << dp[n] << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")