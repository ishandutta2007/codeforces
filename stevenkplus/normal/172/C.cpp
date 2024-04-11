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

struct student {
	int time;
	int id;
	int stop;
	student(int t, int s, int x) {
		id = x;
		stop = s;
		time = t;
	}
	bool operator <(const student &o) const {
		return stop < o.stop;
	}
	student() {
	}
};
const int MAXN = 100100;
int ans[MAXN];

student ar[MAXN];
int main() {
	int n = nextInt(), m = nextInt();
	rep(i,n) {
		int a = nextInt(), b = nextInt();
		ar[i] = student(a, b, i);
	}
	int t = 0;
	for (int x = 0; x < n; x += m) {
		int top = min(n, x + m);
		t = max(t, ar[top - 1].time);
		sort(ar + x, ar + top);
		int wait = 0;
		int prstop = -1;
		int count = 0;
		for (int y = x; y < top; y++) {
			student s = ar[y];
			if (s.stop != prstop) {
				if (count)
					wait += 1 + count / 2;
				count = 0;
			}
			ans[s.id] = t + wait + s.stop;
//			p(s.id);
//			p(ans[s.id]);
//			p(wait);
//			p(s.stop);
//			p(t);
			count++;
			prstop = s.stop;
		}
		wait += 1 + count / 2;
		t = t + wait + prstop;
		t += prstop;
	}
	string sep;
	rep(i,n) {
		cout << sep << ans[i];
		sep = " ";
	}
	cout << "\n";
}

//double eps = 1E-15;
//const int MAXN = 110;
//double ar[MAXN];
//int main() {
//	int a = nextInt();
//	double b = nextInt();
//	double sum = 0;
//	double m = 0;
//	rep(i,a) {
//		ar[i] = nextInt();
//		sum += ar[i];
//		m = max(m, ar[i]);
//	}
//	double each = (sum + b) / a;
//	p(m);
//	if (each + eps < m)
//		cout << "-1" << endl;
//	else {
//		rep(i,a) {
//			printf("%.10f\n", each - ar[i]);
//		}
//	}
//}