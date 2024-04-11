#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, l; cin >> n >> l;
	vi v;
	rep(i, 0, n) {
		int tmp; cin >> tmp; v.push_back(tmp);
	}
	sort(all(v));
	v.push_back(l+l-v[v.size()-1]);
	int wo = v[0]*2;
	rep(i, 0, v.size() - 1) {
		wo = max(wo, v[i + 1] - v[i]);
	}
	cout << wo/2 << (wo%2==1?".5":"");
}