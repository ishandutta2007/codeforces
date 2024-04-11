#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd;
typedef vector<vi> vvi; 

typedef set<int> si;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define ts to_string 

int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;


void solve(){
	int n; cin >> n;
	vvi M(n, vi(n)); 
	vvi Q1(n, vi(n, 0)), Q2(n, vi(n, 0));
	vector<vector<char>> P1(n, vector<char> (n)), P2(n, vector<char> (n));
	for(auto &i : M){
		for(auto &j : i){
			cin >> j;
		}
	}
	int x0 = -1;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j<= i; ++j){
			int best1 = MOD;
			int best2 = MOD;
			int x = i-j;
			int y = j;
			if(M[x][y] == 0)x0 = x;
				if(y > 0){
				best1 = Q1[x][y-1];
				best2 = Q2[x][y-1];
				P1[x][y] = 'R';
				P2[x][y] = 'R';
				
			}
			if(x > 0){
				if(Q1[x-1][y] < best1){
					best1 = Q1[x-1][y];
					P1[x][y] = 'D';
				}
				if(Q2[x-1][y] < best2){
					best2 = Q2[x-1][y];
					P2[x][y] = 'D';
				}
			}
			if(best1 == MOD){
				best1 = 0;
				best2 = 0;
			}
			int fi = 0, tw = 0;
			while((M[x][y] & 1 )== 0 && M[x][y] != 0){
				tw++;
				M[x][y]>>=1;
			}
			while(M[x][y] % 5 == 0 && M[x][y] != 0){
				fi++;
				M[x][y]/=5;
			}
			Q1[x][y] = tw + best1;
			Q2[x][y] = fi + best2;
		}
	}
	for(int i = n-2; i >= 0; --i){
		for(int j = 0; j <= i; ++j){ 
			int best1 = MOD;
			int best2 = MOD;
			int x = n-j-1;
			int y = n-i+j-1;
			if(M[x][y] == 0)x0 = x;
			if(y > 0){
				best1 = Q1[x][y-1];
				best2 = Q2[x][y-1];
				P1[x][y] = 'R';
				P2[x][y] = 'R';
				
			}
			if(x > 0){
				if(Q1[x-1][y] < best1){
					best1 = Q1[x-1][y];
					P1[x][y] = 'D';
				}
				if(Q2[x-1][y] < best2){
					best2 = Q2[x-1][y];
					P2[x][y] = 'D';
				}
			}
			if(best1 == MOD){
				best1 = 0;
				best2 = 0;
			}
			int fi = 0, tw = 0;
			while((M[x][y] & 1 )== 0 && M[x][y] != 0){
				tw++;
				M[x][y]>>=1;
			}
			while(M[x][y] % 5 == 0 && M[x][y] != 0){
				fi++;
				M[x][y]/=5;
			}
			Q1[x][y] = tw + best1;
			Q2[x][y] = fi + best2;
		}
	}
	str ans;
	if(x0 != -1 && 1 <= min(Q1[n-1][n-1], Q2[n-1][n-1])){
		cout << 1 << "\n";
		for(int i = 0; i < x0; ++i){
			cout << 'D';
		}
		for(int i = 0; i < n-1; ++i){
			cout << 'R';
		}
		for(int i = 0; i < n-1-x0; ++i){
			cout << 'D';
		}
		return;
	}
	if(Q1[n-1][n-1] < Q2[n-1][n-1]){
		cout << Q1[n-1][n-1] << "\n";
		int x = n-1, y = n-1;
		while(x || y){
			ans+=P1[x][y];
			if(P1[x][y] == 'R')y--;
			else x--;
		}
		reverse(all(ans));
		cout << ans;
	}
	else{
		cout << Q2[n-1][n-1] << "\n";
		int x = n-1, y = n-1;
		while(x || y){
			ans+=P2[x][y];
			if(P2[x][y] == 'R')y--;
			else x--;
		}
		reverse(all(ans));
		cout << ans;
	}
	//for(int i = 0; i < n; ++i){
		//for(int j = 0; j < n; ++j){
			//cout << Q2[i][j] << " ";
		//}
		//cout << "\n";
	//}
	
	//###
	//###
	//###	

}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 0;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
			cout << "\n";
		}
		return 0;
	}
	solve();
	cout << "\n";		
	return 0;
}