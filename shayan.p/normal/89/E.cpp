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

const int maxn = 1e3 + 10, maxv = 110, inf = 1e9;

int a[maxn], dp[maxn][maxv], opt[maxn][maxv], dp2[maxn][maxv], opt2[maxn][maxv];
string ans;

void f(int l, int r){// alan tooye l hastim ke 0 e va ta r kar darim ke 0 nist
    if(l == r)
	return;
    ans+="A";
    int pt = l;
    while(pt < r){
	ans+="RA";
	pt++;
    }
    while(true){
	pt--;
	while(a[pt] >= a[pt+1]){ // pt > 0
	    ans+="L";
	    pt--;
	}
	ans+="L";
	pt--;
	ans+="A";
	for(int i = pt + 2; i<=r; i++)
	    a[i]--;
	while(r > l && a[r] == 0)
	    r--;
	if(r==l)
	    break;
	while(pt < r-1)
	    ans+="AR", pt++;
	pt++, ans+="A";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
	cin >> a[i];
    while(a[n] == 0)
	n--;
    for(int i = 0; i < maxv; i++)
	dp[0][i] = i;
    for(int i = 1; i <= n; i++){
	for(int j = 0; j < maxv; j++){
	    dp[i][j] = inf;
	    for(int k = a[i]; k < maxv; k++){
		int num = dp[i-1][k] + 3 * k + abs(k - j);
		if(num < dp[i][j])
		    dp[i][j] = num, opt[i][j] = k;
	    }
	}
    }
    for(int i = 0; i < maxv; i++)
	dp2[n+1][i] = i;
    for(int i = n; i >= 1; i--){
	for(int j = 0; j < maxv; j++){
	    dp2[i][j] = inf;
	    for(int k = max(a[i], 1); k < maxv; k++){
		int num = dp2[i+1][k] + 3 * k + abs(k - j);
		if(num < dp2[i][j])
		    dp2[i][j] = num, opt2[i][j] = k;
	    }
	}
    }
    int id = -1, num = dp2[1][0];
    for(int i = 1; i <= n; i++){
	if(a[i] == 0 && dp[i-1][0] + dp2[i+1][0] + 2 * i < num)
	    id = i, num = dp[i-1][0] + dp2[i+1][0] + 2 * i;
    }
    if(id == -1){
	for(int i = 1; i <= n; i++)
	    a[i] = opt2[i][a[i-1]];
    }
    else{
	for(int i = id-1; i >= 1; i--)
	    a[i] = opt[i][a[i+1]];
	for(int i = id+1; i <= n; i++)
	    a[i] = opt2[i][a[i-1]];
    }
    vector<int> zero;
    for(int i = 0; i <= n; i++)
	if(a[i] == 0)
	    zero.PB(i);
    zero.PB(n+1);
    for(int i = 0; i < sz(zero)-1; i++){
	f(zero[i], zero[i+1]-1);
	if(i+1 != sz(zero)-1)
	    for(int j = zero[i]; j < zero[i+1]; j++)
		ans+="AR";
    }
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")