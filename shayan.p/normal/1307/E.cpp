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

const int maxn = 5010, mod = 1e9 + 7;
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

int a[maxn], L[maxn], R[maxn];
int cntl[maxn], cntr[maxn], cntb[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
	cin >> a[i], --a[i];
    for(int i= 0; i < m; i++){
	int f, h;
	cin >> f >> h;
	--f;
	int num = 0;
	L[i] = R[i] = -1;
	for(int j = 0; j < n; j++){
	    num+= a[j] == f;
	    if(num == h){
		L[i] = j;
		break;
	    }
	}
	num = 0;
	for(int j = n-1; j >= 0; j--){
	    num+= a[j] == f;
	    if(num == h){
		R[i] = j;
		break;
	    }
	}
    }
    pii ans = {0, 1};

    for(int j = 0; j < m; j++){
	if(R[j] == -1)
	    continue;
	cntr[ a[ R[j] ] ]++;
    }
    for(int j = 0; j < n; j++){
	if(cntr[j] > 0)
	    ans.F++, ans.S = 1ll * ans.S * cntr[j] % mod;
    }
    
    for(int i = 0; i < n; i++){
	memset(cntl, 0, sizeof cntl);
	memset(cntr, 0, sizeof cntr);
	memset(cntb, 0, sizeof cntr);

	int id = -1;
	for(int j = 0; j < m; j++){
	    bool A = L[j] != -1 && L[j] <= i;
	    bool B = R[j] != -1 && R[j] > i;
	    if(A && B)
		cntb[ a[ L[j] ] ]++;
	    else if(A)
		cntl[ a[ L[j] ] ]++;
	    else if(B)
		cntr[ a[ R[j] ] ]++;
	    if(L[j] == i)
		assert(id == -1), id = j;
	}
	if(id == -1)
	    continue;
	pii num = {0, 1};
	for(int j = 0; j < n; j++){
	    if(a[ L[id] ] == j)
		continue;
	    int c = 0;
	    bool any = 0;
	    if(cntl[j] && cntr[j])
		any = 1, c = (1ll * c + 1ll * cntl[j] * cntr[j]) % mod;
	    if(cntl[j] && cntb[j])
		any = 1, c = (1ll * c + 1ll * cntl[j] * cntb[j]) % mod;
	    if(cntb[j] && cntr[j])
		any = 1, c = (1ll * c + 1ll * cntb[j] * cntr[j]) % mod;
	    if(cntb[j] >= 2)
		any = 1, c = (1ll * c + 1ll * cntb[j] * (cntb[j]-1)) % mod;
	    if(any){
		num.F+= 2;
		num.S = 1ll *num.S * c %mod;
		continue;
	    }

	    c = 0, any = 0;
	    if(cntl[j])
		any = 1, c = (c + cntl[j]) %mod;
	    if(cntr[j])
		any = 1, c = (c + cntr[j]) %mod;
	    if(cntb[j])
		any = 1, c = (1ll * c + 2ll * cntb[j]) %mod;
	    if(any){
		num.F++;
		num.S = 1ll * num.S * c %mod;
	    }		
	}

	int j = a[ L[id] ];
	if(cntr[j] + cntb[j] - (R[id] > i)){
	    num.F+= 2;
	    num.S = 1ll * num.S * (cntr[j] + cntb[j] - (R[id] > i)) %mod;
	}
	else{
	    num.F++;
	}
	
	if(ans.F < num.F)
	    swap(ans, num);
	if(ans.F == num.F)
	    ans.S = (ans.S + num.S) % mod;
    }
    return cout << ans.F << " " << ans.S << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")