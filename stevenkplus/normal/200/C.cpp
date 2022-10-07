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
struct team {
	int wins;
	int score;
	int miss;
	int games;
	string name;
	team() {
		games = 0;
	}
	team(string s) {
		name = s;
		wins = 0;
		score = 0;
		miss = 0;
		games = 0;
	}
};
bool better(team a, team b) {
	if (a.wins == b.wins) {
		if (a.score - a.miss == b.score - b.miss) {
			if (a.score == b.score) {
				return a.name < b.name;
			}
			return a.score > b.score;
		}
		return a.score - a.miss > b.score - b.miss;
	}
	return a.wins > b.wins;
}
vector<team> teams;
int main() {
	teams.pb(team());
	int ii = 1;
	map<string, int> map;
	rep(i,5) {
		string a = next(), b = next(), c = next();
		int dex = c.find(":");
		int sa, sb;
		sscanf(c.substr(0, dex).c_str(), "%d", &sa);
		sscanf(c.substr(dex + 1).c_str(), "%d", &sb);
		if (!map[a]) {
			map[a] = ii++;
			teams.pb(team(a));
		}
		if (!map[b]) {
			map[b] = ii++;
			teams.pb(team(b));
		}
		team &aa = teams[map[a]], &bb = teams[map[b]];
		if (sa > sb) {
			aa.wins += 3;
		} else if (sa == sb) {
			aa.wins++;
			bb.wins++;
		} else if (sa < sb) {
			bb.wins+=3;
		}
		aa.score += sa;
		bb.score += sb;
		aa.miss += sb;
		bb.miss += sa;
		aa.games++;
		bb.games++;
	}
	team berl = teams[map["BERLAND"]];
	team *oth;
	repi(i,map) {
		team &t = teams[i->se];
		if (t.games == 2 && t.name != berl.name) {
			oth = &t;
			break;
		}
	}

	int bx = 0;
	int by = 0;
	berl.wins += 3;
	for (int y = 0; y < 100; y++) {
		for (int x = y+1; x < 100; x++) {
			berl.score += x;
			berl.miss += y;
			oth->score += y;
			oth->miss += x;
			int abv = 0;
			if(x==6&&y==0) {
				int kkk = 0;
			}
			repi(i,map) {
				team t = teams[i->se];
				if (t.name != berl.name && better(t, berl)) {
//					printf("team %s is better.\n",t.name.c_str());
					abv++;
				}
				else {
//					printf("team %s is not better\n",t.name.c_str());
				}
			}
			if (abv <= 1) {
				if (!bx || (x - y < bx - by)) {
					bx = x;
					by = y;
				}
			}

			oth->score -= y;
			oth->miss -= x;

			berl.miss -= y;
			berl.score -= x;
		}
	}
	if (bx)
		printf("%d:%d\n", bx, by);
	else
		cout << "IMPOSSIBLE\n";

}