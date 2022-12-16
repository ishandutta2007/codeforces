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
typedef long double ld;

const int maxn = 2010;

double A[maxn], B[maxn];
ld in[maxn], out[maxn];
int arr[maxn];
bool typo[maxn], typi[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, a, b;
    cin >> n >> a >> b;
    a = min(a, n);
    b = min(b, n);
    
    for(int i = 0; i < n; i++){
	cin >> A[i];
    }
    for(int i = 0; i < n; i++){
	cin >> B[i];
    }
    for(int i = 0; i < n; i++){
	arr[i] = i;
    }
    
    ld l = -2, r = 2;
    for(int _ = 0; _ < 100; _++){
	ld mid = (l+r) / 2;

	for(int i = 0; i < n; i++){
	    out[i] = max( ld(0), A[i] + mid );
	    in[i] = max( ld(B[i]), 1 - (1 - A[i]) * (1 - B[i]) + mid );
	    
	    typo[i] = out[i] != ld(0);
	    typi[i] = in[i] != B[i];
	}
	sort(arr, arr + n, [](int i, int j){   return (pair<ld,int>){ in[i] - out[i], - typi[i] + typo[i] } > (pair<ld,int>){ in[j] - out[j], - typi[j] + typo[j] } ; } );

	int num = 0;
	for(int i = 0; i < b; i++){
	    num+= typi[ arr[i] ];
	}
	for(int i = b; i < n; i++){
	    num+= typo[ arr[i] ];
	}

	if(a >= num)
	    l = mid;
	else
	    r = mid;
    }

    ld ans = 0;
    for(int i = 0; i < b; i++){
	ans+= in[ arr[i] ];
    }
    for(int i = b; i < n; i++){
	ans+= out[ arr[i] ];
    }
    ans-= a * l;
    return cout << setprecision(10) << fixed << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")