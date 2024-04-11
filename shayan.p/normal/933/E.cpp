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

const int maxn = 3e5 + 10, mod = 1e9 + 7;
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

int a[maxn], dpp[maxn];
ll dp[maxn];
bool is[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
	cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[2];
    for(int i = 3; i <= n; i++){
	dp[i] = min( max(a[i], a[i-1]) + dp[i-3], a[i] + dp[i-2] );
	if(dp[i] == dp[i-3] + max(a[i], a[i-1]))
	    dpp[i] = 2;
	else
	    dpp[i] = 1;
    }
    
    vector<int> vec, ans;
    
    int tmp = dp[n] < dp[n-1] ? n : (n-1);
    while(tmp > 2){
	if(dpp[tmp] == 2){
	    is[tmp-1] = 1;
	    tmp-=3;
	}
	else{
	    tmp-=2;
	}
    }
    for(int i = 1; i <= n; i++){
	if(is[i])
	    vec.PB(i);
    }
    for(int i = 1; i < n; i++){
	if(is[i] == 0)
	    vec.PB(i);
    }
    for(int pos : vec){
	int mn = min(a[pos], a[pos+1]);
	if(mn != 0){
	    ans.PB(pos);
	    a[pos]-= mn, a[pos+1]-= mn;
	}
    }
    cout << sz(ans) << "\n";
    for(int pos : ans){
	cout << pos << "\n";
    }
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")