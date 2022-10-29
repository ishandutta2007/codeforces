#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solveA() {
	int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
	cout << ((a - b) * n <= (c + d) && (a + b) * n>=(c - d) ? "YES\n" : "NO\n");
}
void solveB() {

}
void solveC() {

}
void solveD() {

}
void solveE() {

}
void solveF() {

}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int t; cin >> t;

	while (t--) {
		solveA();
	}
	return 0;
}