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

const int maxn = 110, mod = 1e9 + 7;
const ll inf = 1e18;

string s[maxn];
int n,m;

bool f0(){
    for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	    if(s[i][j] != 'A')
		return 0;
    return 1;
}
bool f1(){
    bool a0 = 1, a1 = 1, b0 = 1, b1 = 1;
    for(int i = 0; i < n; i++)
	a0 &= s[i][0] == 'A', a1 &= s[i][m-1] == 'A';
    for(int i = 0; i < m; i++)
	b0 &= s[0][i] == 'A', b1 &= s[n-1][i] == 'A';
    return a0 || a1 || b0 || b1;
}
bool f2(){
    if(s[0][0] == 'A' || s[0][m-1] == 'A' || s[n-1][0] == 'A' || s[n-1][m-1] == 'A')
	return 1;
    for(int i = 0; i < n; i++){
	bool x = 1;
	for(int j = 0; j < m; j++)
	    x &= s[i][j] == 'A';
	if(x == 1)
	    return 1;
    }
    for(int j = 0; j < m; j++){
	bool x = 1;
	for(int i = 0; i < n; i++)
	    x &= s[i][j] == 'A';
	if(x == 1)
	    return 1;
    }
    return 0;
}
bool f3(){
    for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	    if(i == 0 || j == 0 || i == n-1 || j == m-1)
		if(s[i][j] == 'A')
		    return 1;		
	}
    }
    return 0;
}
bool f4(){
    for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	    if(s[i][j] == 'A')
		return 1;
    return 0;
}

int solve(){
    if(f0())
	return 0;
    if(f1())
	return 1;
    if(f2())
	return 2;
    if(f3())
	return 3;
    if(f4())
	return 4;
    return 5;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	    cin >> s[i];
	int num = solve();
	if(num == 5)
	    cout << "MORTAL\n";
	else
	    cout << num <<"\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")