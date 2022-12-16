// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define X first
#define Y second
#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int, int> point;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10, inf = 1e9;

string s;
int n;
int dp[2 * maxn][5][5];

int A[5][5], B[5][5], tmp[5][5];

void f(int A[][5] , int B[][5], int C[][5]){// A = B * C
    for(int a = 0; a < 5; a++)
	for(int b = 0; b < 5; b++)
	    tmp[a][b] = inf;
    for(int a = 0; a < 5; a++)
	for(int b = 0; b < 5; b++)
	    for(int c = a; c <= b; c++)
		tmp[a][b] = min( tmp[a][b], B[a][c] + C[c][b] );
    for(int a = 0; a < 5; a++)
	for(int b = 0; b < 5; b++)
	    A[a][b] = tmp[a][b];    
}

void build(){
    for(int i = 0 ; i < n; i++){
	for(int j = 0; j < 5; j++)
	    for(int k = 0; k < 5; k++)
		dp[i + n][j][k] = j == k ? 0 : inf;
	if(s[i] == '2')
	    dp[i + n][0][1] = 0, dp[i + n][0][0] = 1;
	else if(s[i] == '0')
	    dp[i + n][1][2] = 0, dp[i + n][1][1] = 1;
	else if(s[i] == '1')
	    dp[i + n][2][3] = 0, dp[i + n][2][2] = 1;
	else if(s[i] == '6')
	    dp[i + n][3][4] = 0, dp[i + n][3][3] = 1;	
    }
    for(int i = n-1; i >= 1; i--){
	f( dp[i], dp[2*i], dp[2*i+1] );
    }
}
int ask(int l, int r){
    for(int a = 0; a < 5; a++)
	for(int b = 0; b < 5; b++)
	    A[a][b] = B[a][b] = a == b ? 0 : inf;
    for( l+= n, r+= n; l < r; l>>=1, r>>=1){
	if(l & 1)
	    f(A, A, dp[l++]);
	if(r & 1)
	    f(B, dp[--r], B);
    }
    f(A, A, B);
    return A[0][3];
}

vector<int> vec;
int sm[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> n >> q >> s;
    build();

    for(int i = 0; i < n; i++){
	sm[i] = (i==0 ? 0 : sm[i-1]) + (s[i] == '6');
	if(s[i] == '7')
	    vec.PB(i);
    }
    
    while(q--){
	int l, r;
	cin >> l >> r;
	--l;
	int id = lower_bound(vec.begin(), vec.end(), r) - vec.begin() -1;
	if(id == -1){
	    cout << -1 << "\n";
	    continue;
	}
	int num = sm[r-1] - sm[ vec[id] ];
	r = vec[id];
	int ans = ask(l, r);
	cout << ( ans == inf ? -1 : ans + num ) <<"\n";	
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")