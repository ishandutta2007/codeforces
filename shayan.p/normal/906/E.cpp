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
int f[maxn], fb[maxn], ln[maxn], df[maxn], dpv[maxn], bstv[maxn], C;
int str[maxn], n;
int lst;

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



int dp[maxn], bst[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    str[0] = -1;
    f[0] = -1;
    df[0] = -1;
    
    string ss1, ss2, s;
    cin >> ss1 >> ss2;
    for(int i = 0; i < sz(ss1); i++){
	s+= ss1[i];
	s+= ss2[i];
    }

    for(int i = 1; i <= sz(s); i++){
	add_char( s[i-1] );
	dp[i] = inf;
	if(i & 1)
	    continue;
	for(int vert = lst; vert != 0; vert = fb[vert]){
	    int l = ln[ fb[ vert ] ] + df[ vert ];
	    int x = dp[ i - l ] + (l > 2);
	    int bstx = l;
	    
	    if( df[vert] == df[ f[vert] ] )
		if( dpv[ f[vert] ] < x )
		    x = dpv[ f[ vert ] ], bstx = df[ vert ] + bstv[ f[ vert ] ];
	    dpv[ vert ] = x;
	    bstv[ vert ] = bstx;
	    if( x < dp[i] )
		dp[i] = x, bst[i] = bstx;
	}	
    }
    if( dp[n] == inf )
	return cout << -1 << endl, 0;
    cout << dp[n] << endl;
    int nw = n;
    while( nw > 0 ){
	if( bst[nw] != 2 )
	    cout << 1 + ( (nw - bst[nw]) / 2 ) << " " << (nw / 2) << "\n";
	nw-= bst[nw];
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")