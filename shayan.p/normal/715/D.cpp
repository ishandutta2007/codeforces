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

int n;
ll t;
bool b[2][2];

vector<pair<pii, pii> > ans;

void go(){
    while(t){
	int r = t % 6;
	t/=6;

	memset(b, 0, sizeof b);
	if(r == 1)
	    b[0][0] = 1;
	if(r == 2)
	    b[0][0] = b[1][0] = 1;
	if(r == 3)
	    b[0][1] = 1;
	if(r == 4)
	    b[0][0] = b[0][1] = 1;
	if(r == 5)
	    b[0][0] = b[0][1] = b[1][0] = 1;
	
	if(t){
	    ans.PB({{n+3, n+1}, {n+3, n+2}});
	    ans.PB({{n+4, n+1}, {n+4, n+2}});
	    ans.PB({{n+3, n}, {n+4, n}});
	    ans.PB({{n+5, n+1}, {n+6, n+1}});
	    
	    ans.PB({{n+1, n+3}, {n+2, n+3}});
	    ans.PB({{n+1, n+4}, {n+2, n+4}});
	    ans.PB({{n, n+3}, {n, n+4}});
	    ans.PB({{n+1, n+5}, {n+1, n+6}});	    
	}
	else{
	    ans.PB({{n+2, n+2}, {n+2, n+3}});
	    ans.PB({{n+2, n+2}, {n+3, n+2}});	    
	}
	for(int i = 0; i < 2; i++)
	    if(b[0][i] == 0)
		ans.PB({{n+2, n+i}, {n+3, n+i}});
	for(int i = 0; i < 2; i++)
	    if(b[1][i] == 0)
		ans.PB({{n+i, n+2}, {n+i, n+3}});
	n+=2;
    }
    n+=2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    cin >> t;
    go();
    for(int i = 0; i < sz(ans); i++)
	if(max({ans[i].F.F, ans[i].F.S, ans[i].S.F, ans[i].S.S}) >= n)
	    swap(ans[i], ans[sz(ans)-1]), ans.pop_back();
    cout << n << " " << n << endl << sz(ans) << endl;
    for(auto x : ans)
	cout << x.F.F+1 << " " << x.F.S+1 << " " << x.S.F+1 << " " << x.S.S+1 << "\n";
    return 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")