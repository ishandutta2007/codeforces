#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;
typedef pair<pii, int> circ;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
const int inf = 1 << 30;
char buf[1000];
string nextLine(int length = 100) {
	cin.getline(buf, length);
	string s(buf);
	return s;
}
string next(int length = 100) {
	string tmp;
	cin >> tmp;
	return tmp;
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}
const int MAXN = 110;
const int MAXS = 10;
int s = 8;
char grid[MAXS][MAXS];
bool valid(int x, int y, int turn) {
	if (x < 0 || y < 0 || x >= s || y >= s)
		return false;
	int X = x - turn;
	return (X < 0 || grid[X][y] != 'S');
}
bool found = false;
int turn = 0;
int x=7, y=0;
void dfs() {
	if (turn >= 8)
		found = true;
	if (found)
		return;
	if (!valid(x, y, turn)) {
		return;
	}
	rep(dx,3) {
		x += dx-1;
		rep(dy,3) {
			y += dy-1;
			if (valid(x, y, turn)) {
				turn++;
				dfs();
				turn--;
			}
			y -= dy-1;
		}
		x -= dx-1;
	}
}
int main() {
	rep(i,8) {
		string s = next();
		rep(j,8) {
			grid[i][j] = s[j];
		}
	}
	dfs();
	cout << (found ? "WIN" : "LOSE") << endl;
}