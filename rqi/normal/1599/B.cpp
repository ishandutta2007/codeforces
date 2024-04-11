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
#define ROF(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}

tcT, class U> T fstTrue(T lo, T hi, U f){
	++hi; assert(lo <= hi);
	while(lo < hi){
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1;
	}
	return lo;
}

struct Eff{

bool solveRecur(ll N, ll A, ll B, string DA, string DB){
	// cout << N << " " << A << " " << B << " " << DA << " " << DB << "\n";
	// cout.flush();
	if(DA != DB){
		if(A == 0 || A == N-1){
			DA = DB;
			return solveRecur(N, A, B, DA, DB);
		}
		else if(B == 0 || B == N-1){
			DB = DA;
			return solveRecur(N, A, B, DA, DB);
		}

		if(DA == "left"){
			swap(DA, DB);
			// swap(A, B);
			// cout << "REV" << "\n";
			A = N-1-A;
			B = N-1-B;
			return 1^solveRecur(N, A, B, DA, DB);
		}

		if(A < B){
			swap(A, B);
			N--;
			A--;
			return solveRecur(N, A, B, DA, DB);
		}
		else if(A == B){
			A++;
			B--;

			N--;
			A--;
			return solveRecur(N, A, B, DA, DB);
		}

		ll min_dist = min(N-1-A, B);
		return solveRecur(N, A+min_dist, B-min_dist, DA, DB);
	}

	map<string, bool> to_bool; to_bool["left"] = 0; to_bool["right"] = 1;
	map<bool, string> to_str; to_str[0] = "left"; to_str[1] = "right";
	//same direction


	if(DA == "left"){
		DA = to_str[to_bool[DA]^1];
		DB = to_str[to_bool[DB]^1];
		A = N-1-A;
		B = N-1-B;


		return 1^solveRecur(N, A, B, DA, DB);
	}

	if(A == B){
		if(A == 0){
			return 1;
		}

		// cout << N << " " << A << " " << B << " " << DA << " " << DB << "\n";
		return 0;
	}

	if(A < B){
		return solveRecur(N, B, A+1, DB, DA);
	}

	assert(A > B);
	if((N+A-B+(N&1)) % 2 == 0){
		// cout << N << " " << A << " " << B << " " << DA << " " << DB << " " << 0 << "\n";
		return 0;
	}
	return 1;
}
void solveTestCase(){
	ll N, A, B;
	cin >> N >> A >> B;
	string DA, DB;
	cin >> DA >> DB;

	// cout << N << " " << A << " 	" << B << " " << DA << " " << DB << "\n";
	if(solveRecur(N, A, B, DA, DB)){
		cout << N-1 << "\n";
	}
	else{
		cout << 0 << "\n";
	}
}

void solve(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solveTestCase();
	}
}

};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	Eff e; e.solve();
}