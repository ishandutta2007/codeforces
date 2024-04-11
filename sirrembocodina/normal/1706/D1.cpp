#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define int int64_t

// Type aliases

using ll = long long;
using str = string;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

// Vector Operations

#define sz (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)

// Pairs

#define mp make_pair
#define sec second
#define fir first

// Sets and Maps

#define ins insert
#define ez erase
#define cnt count

// Math

#define MAX_INT 1e18*9

// Loops

#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define printv(v) cout << "["; for(int i =0;i<v.size();i++){ cout << v[i]; if(i!=v.size()-1){ cout << ", "; } } cout << "]" << endl;

// To check time of submission, put below line after reading input
// clock_t z = clock();
#define time_up cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "\n";

// __gcd(20, 60) for in-built GCD function

int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	vi a(n);
	int total_max = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		total_max = max(total_max, a[i]);
	}
	int final_ans = 3010;
	int max_amount = 1;
	while(max_amount <= total_max){
		int min_so_far = total_max + 1;
		bool valid = true;
		for(int i = 0; i < n; i++){
			if(a[i] / k > max_amount) {
				valid = false;
				break;
			}
			
			/*
			
			
			
			down((a + 1 - max_amount) / (max_amount + 1)) = p
			
			
			*/
			
			
			
			int curr_val = a[i] / (max_amount + 1) + 1;
			curr_val = a[i] / curr_val;
			min_so_far = min(curr_val,min_so_far);
		}
		if(!valid) {
			max_amount++;
			continue;
		}
		int curr_ans = max_amount - min_so_far;
		final_ans = min(final_ans, curr_ans);
		max_amount++;
	}
	cout << final_ans << "\n";
}

int32_t main(){
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
}