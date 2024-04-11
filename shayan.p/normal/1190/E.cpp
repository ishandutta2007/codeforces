// Never let them see you bleed...
// Shayan.P  2020-05-07
 
#include<bits/stdc++.h>
 
#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef long double db;
typedef pair<db, db> pd;
typedef pair<ll, ll> pll;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
 
template<typename A, typename B>
ostream& operator << (ostream& out, pair<A, B> p){
    out << "{" << p.F << ", " << p.S << "}";
    return out;
}
 
db operator * (pd a, pd b){
    return a.F * b.S - a.S * b.F;
}
db operator ^ (pd a, pd b){
    return a.F * b.F + a.S * b.S;
}
pd operator * (pd a, db k){
    return {a.F * k, a.S * k};
}
pd operator + (pd a, pd b){
    return {a.F + b.F, a.S + b.S};
}
pd operator - (pd a, pd b){
    return {a.F - b.F, a.S - b.S};
}
db abs(pd p){
    return sqrt(p ^ p);
}
db abs2(pd p){
    return p ^ p;
}
pair<pd, pd> intersect(pd a, pd b, db A){
    db C = abs(b-a);
    db B = sqrt(C*C - A*A);
    db H = A * B / C;
    pd vecx = (b-a);
    db cof = sqrt(A * A - H * H) / C;
    pd vecy = (pd){vecx.S, -vecx.F} * (H / C);
    return {a + vecx * cof + vecy, a + vecx * cof - vecy};
}
 
pd p[maxn];
int n;
 
pd _seg[maxn][2];
pii seg[maxn];
int arr[2 * maxn];

int sp[20][2 * maxn], to[2 * maxn], f[2 * maxn], g[2 * maxn];

int calc(db r){
    for(int i = 0; i < n; i++){
	auto _p = intersect({0,0}, p[i], r);
	_seg[i][0] = _p.F;
	_seg[i][1] = _p.S;	
    }
    iota(arr, arr + 2*n, 0);
    auto cmp = [&](int i, int j){
		   pd a = _seg[i>>1][i&1], b = _seg[j>>1][j&1];
		   if(a.S < 0 && b.S >= 0)
		       return false;
		   if(a.S >= 0 && b.S < 0)
		       return true;
		   if(a.S >= 0)
		       return a.F > b.F;
		   else
		       return a.F < b.F;
	       };    
    sort(arr, arr+ 2*n, cmp);
    int m = 2*n;
    for(int i = 0; i < 2*n; i++){
	if(arr[i] & 1)
	    seg[arr[i]>>1].S = i;
	else
	    seg[arr[i]>>1].F = i;
    }
    memset(to, -1, sizeof to);
    for(int i = 0; i < n; i++){
	to[seg[i].F] = seg[i].S;
    }
    sp[0][m-1] = m;
    for(int i = 0; i < n; i++){
	if(seg[i].F <= seg[i].S && seg[i].S < m-1)
	    sp[0][m-1] = min(sp[0][m-1], seg[i].S+1);
    }
    if(sp[0][m-1] == m)
	return 1;
    int num = sp[0][m-1];
    for(int i = m-1; i > 0; i--){
	if(to[i] != -1)
	    num = min(num, ((to[i]-i+m) % m));
	num++;
	if(num >= m)
	    return 1;
	sp[0][i-1] = num;
    }
    int pt = 0;
    while(pt < 20){
	for(int i = 0; i < m; i++){
	    int A = sp[pt][i];
	    int B = sp[pt][(i + A) %m];
	    if(A + B >= m)
		goto OUT;
	    sp[pt+1][i] = A + B;
	}
	pt++;
    }
 OUT:;
    memset(f, 0, sizeof f);
    int ans = 0;
    for(int w = pt; w >= 0; w--){
	bool is = 0;
	for(int i = 0; i < m; i++){
	    int A = f[i];
	    int B = sp[w][(i + A) %m];
	    if(A + B >= m)
		is = 1;
	    g[i] = A + B;
	}
	if(is == 0){
	    memcpy(f, g, sizeof f);
	    ans+= 1<<w;
	}
    }
    return ans+1;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int m;
    cin >> n >> m;
    db l = 0.001, r = 1000000;
    for(int i = 0; i < n; i++){
	cin >> p[i].F >> p[i].S;
	r = min(r, abs(p[i]));
    }
    bool NO = 1;
    sort(p, p+n);
    n = unique(p, p+n) - p;
    for(int Q = 0; l < r && Q < 40; Q++){
	db mid = (l+r) / 2;
	if(calc(mid) <= m)
	    l = mid, NO = 0;
	else
	    r = mid;
    }
    if(NO)
	l = 0;
    return cout << setprecision(10) << fixed << l << endl, 0;
}