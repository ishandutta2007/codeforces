#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double lf;
typedef long double Lf;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;

#define TRACE(x) cerr << #x << "  " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define _ << " " <<

#define fi first
#define sec second
#define mp make_pair

const int MAXN = 50100;
const int K = 1200;

int n, start, x;

bool bio[MAXN];

set <pii> s;

int ans = -1;
int cnt;

void pitaj(int in) {
	cnt++;
	assert(in >= 1 && in <= n && cnt <= 1999);
	bio[in] = 1;
	printf("? %d\n",in);
	fflush(stdout);
	int val, next;
	scanf("%d %d",&val,&next);
	s.insert(mp(val, next));
	if (val >= x) {
		if (ans == -1) ans = val;
		ans = min(ans, val);
	}
}

int myrand() {
	ll ret = rand() % 1232152;
	ret *= rand()%123124;
	return ret % n;
}

int main() {
	srand(time(NULL));
	scanf("%d %d %d",&n,&start,&x);
	pitaj(start);
	bio[start] = 1;

	if (n <= 1999) {
		FOR(i, 1, n + 1) 
			if (i != start) pitaj(i);
	}
	else {
		REP(i, K - 1) {
			int x = myrand()%n;
			while (bio[x + 1]) x = myrand();
			pitaj(x + 1);
		}

		REP(i, 2000 - K - 1) {
			set <pii> :: iterator it = s.lower_bound(mp(x, -200));
			if (it == s.begin()) {
				printf("! %d\n",(*it).fi);
				fflush(stdout);
				return 0;
			}
			int tmp = -1;
			if (it != s.end()) tmp = (*it).fi;
			it--;
			int t = (*it).sec;
			if (t != -1 && bio[t]) {
				printf("! %d\n",tmp);
				fflush(stdout);
				return 0;
			}
			if (t != -1) pitaj(t);
		}
	}

	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}