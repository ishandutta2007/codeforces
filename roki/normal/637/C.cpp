//C
#pragma comment(linker, "/STACK:268435456")

#include<iostream>
#include<cstdio>

#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<stack>

#include<iomanip>
#include<memory.h>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define sz(v) (int)(v.size())
#define hash archash
#define next arcnext
#define link arclink
#define y0 arcy0
#define y1 arcy1
#define log2 arclog2

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { return a / gcd (a, b) * b; }
template<class T> T sign(T a) { return a > 0 ? 1 : (a < 0 ? -1 : 0); }

//template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << p.X << " " << p.Y << " "; }
//template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { forn(i, sz(a)) { if (i) out << ' '; out << a[i]; } return out << " "; }
//template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }

typedef long long li;
typedef unsigned long long uli;
typedef long double ld;
typedef pair <int, int> pt;
typedef vector <int> vi; 
typedef vector <vector <int> > vvi;
typedef vector <pair <int, int> > vpt; 

const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};
const int dxK[] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int dyK[] = { 0,  1, 1, 1, 0, -1, -1, -1};
const int dxKn[] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int dyKn[] = { 1,  2, 2, 1, -1, -2, -2, -1};

const int N = int(1e6) + 9;
const int M = int(2e2) + 9;
const int LOGN = 22;
const int SQN = 350;
const int MOD = int(1e9) + 7;
const int INF = 1e9 + 100;
const li INF64 = 2e18;
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

int n;
string s[N];

void solve(){
	cin >> n;
	if(n == 1){
		cout << 6;
		return;
	}
	forn(i, n)
		cin >> s[i];

	int mn = 6;
	forn(i, n) forn(j, i){
		int cur = 0;
		forn(k, 6)
			cur += s[i][k] != s[j][k];
		mn = min(mn, cur);
	}

	cout << (mn - 1) / 2;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand(time(NULL));

	srand(time(NULL));
	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;   

	solve();

	return 0;
}