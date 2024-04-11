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
const ll infl = ll(1) << 60;
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
const int MAXN = 1100;
int RANKSTYLE;
bool compare(const int ar1[MAXN], const int ar2[MAXN]) {
	rep(i,MAXN) {
		if (ar1[i] != ar2[i])
			return ar1[i] < ar2[i];
	}
	return true;
}
struct racer {
	string name;
	int points;
	int places[MAXN];
	bool operator <(const racer &o) const {
		if (RANKSTYLE == 0) {
			if (points == o.points)
				return compare(places, o.places);
			else
				return points < o.points;
		} else {
			if (places[0] == o.places[0]) {
				if (points == o.points)
					return compare(places, o.places);
				else
					return points < o.points;
			} else {
				return places[0] < o.places[0];
			}
		}
	}
	racer(string s) {
		name = s;
		points = 0;
	}
};
const int MAXRANK = 10;
int ar[MAXRANK] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };
vector<racer> racers;
map<string, int> m;
racer best() {
	int best = 0;
	rep(i,sz(racers)) {
		if(racers[best]<racers[i]) {
			best = i;
		}
	}
	return racers[best];
}
int main() {
	int T = nextInt();
	rep(i,T) {
		int N = nextInt();
		rep(j,N) {
			string name = next();
			if (!m[name]) {
				racer r = racer(name);
				racers.pb(r);
				m[name] = sz(racers);
			}
			racer &r = racers[m[name] - 1];
			if (j < MAXRANK)
				r.points += ar[j];
			r.places[j]++;
		}
	}
	int &i = RANKSTYLE;
	for (i = 0; i <= 1; i++) {
		cout << best().name << endl;
	}
}