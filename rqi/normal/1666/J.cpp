#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const ll BIG = 1e18;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}

const int mx = 205;
ll c[mx][mx];
ll csum[mx][mx];

void genCsum(){
	for(int i = 1; i < mx; i++){
		for(int j = 1; j < mx; j++){
			csum[i][j] = c[i][j]+csum[i-1][j]+csum[i][j-1]-csum[i-1][j-1];
		}
	}
}

ll getSum(int x_l, int x_r, int y_l, int y_r){
	if(x_l > x_r || y_l > y_r) return 0;
	return csum[x_r][y_r]-csum[x_l-1][y_r]-csum[x_r][y_l-1]+csum[x_l-1][y_l-1];
}

int n;

ll dp[mx][mx];

int ans[mx];

void genAns(int L, int R, int p = 0){
	if(L > R) return;
	int actual_M = -1;
	for(int M = L-1; M <= R; M++){
		ll cross1 = getSum(L, M-1, M, n);
		ll cross2 = getSum(L, M-1, 1, L-1);
		ll cross3 = getSum(M+1, R, 1, M);
		ll cross4 = getSum(M+1, R, R+1, n);
		
		
		
		ll val = dp[L][M-1]+dp[M+1][R]+cross1+cross2+cross3+cross4;
		if(val == dp[L][R]){
			actual_M = M;
		}
	}
	assert(actual_M != -1);
	ans[actual_M] = p;
	genAns(L, actual_M-1, actual_M);
	genAns(actual_M+1, R, actual_M);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
		}
	}

	genCsum();

	for(int i = 0; i <= n+1; i++){
		for(int j = 0; j <= n+1; j++){
			dp[i][j] = BIG;
		}
	}

	for(int L = 1; L <= n+1; L++){
		dp[L][L-1] = 0;
	}

	for(int i_sz = 0; i_sz < n; i_sz++){
		for(int L = 1; L+i_sz <= n; L++){
			int R = L+i_sz;
			for(int M = L-1; M <= R; M++){
				ll cross1 = getSum(L, M-1, M, n);
				ll cross2 = getSum(L, M-1, 1, L-1);
				ll cross3 = getSum(M+1, R, 1, M);
				ll cross4 = getSum(M+1, R, R+1, n);
				
				
				
				ll val = dp[L][M-1]+dp[M+1][R]+cross1+cross2+cross3+cross4;
				// if(val < BIG){
				// 	cout << L << " " << R << " " << M << " " << cross1 << " " << cross2 << " " << val << "\n";
				// }
				
				ckmin(dp[L][R], dp[L][M-1]+dp[M+1][R]+cross1+cross2+cross3+cross4);

			}
			// cout << L << " " << R << " " << dp[L][R] << "\n";
		}
	}

	genAns(1, n);
	for(int i = 1; i <= n; i++){
		cout << ans[i];
		if(i+1 <= n){
			cout << " ";
		}
	}
	cout << "\n";

}