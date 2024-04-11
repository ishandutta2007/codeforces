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
const int MAXN = 1010;
bool ar[MAXN][MAXN];
int main() {
	int N = nextInt(), M = nextInt();
	int ans = -1;
	rep(i,M) {
		int a = nextInt() - 1, b = nextInt() - 1;
		ar[a][b] = true;
		for (int x = a - 2; x <= a; x++) {
			for (int y = b - 2; y <= b; y++) {
				if (x >= 0 && y >= 0) {
					bool g = true;
					for (int xx = x; xx <= x + 2; xx++) {
						for (int yy = y; yy <= y + 2; yy++) {
							if (!ar[xx][yy]) {
								g = false;
								break;
							}
						}
						if (!g)
							break;
					}
					if (g) {
						ans = i + 1;
						break;
					}
				}
			}
			if (ans != -1)
				break;
		}
		if (ans != -1)
			break;
	}
	cout << ans << endl;
}