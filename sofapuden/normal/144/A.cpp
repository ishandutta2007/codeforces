#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;


int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n; cin >> n;
	vi v;
	int besti = 0,bestv = 0;
	int worsti = 0,worstv = INT_MAX;
	rep(i, 1, n+1){
		int tmp; cin >> tmp;
		if (tmp <= worstv) {
			worstv = tmp;
			worsti = i;
		}
		if (tmp > bestv) {
			besti = i;
			bestv = tmp;
		}
	}
	int ans = 0;
	if (worsti < besti) {
		ans--;
	}
	ans += besti - 1;
	ans += n - worsti;
	cout << ans;


}