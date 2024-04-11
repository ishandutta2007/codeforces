#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

struct Event {
    int tp;
    int x, y;

    Event(){}
    Event(int x, int y, int tp) : x(x), y(y), tp(tp){}

    bool operator<(const Event &a) const {
	if (x != a.x) return x < a.x;
	else return tp < a.tp;
    }
};

int n, k;
ll ans[100010];
vector<Event> vec;
int cs[300010];
int la[300010];
vi ys;

int main() {
    scanf("%d %d", &n, &k);

    rep(i, n) {
	int x, y;
	scanf("%d %d", &x, &y);
	vec.eb(x, y, 1);
	vec.eb(x + k, y, -1);
	ys.pb(y); ys.pb(y + k);
    }

    sort(ALL(ys));
    ys.erase(unique(ALL(ys)), ys.end());

    sort(ALL(vec));

    for (int i = 0; i < vec.size(); ) {
	int j = i;

	while (j < vec.size() && vec[j].x == vec[i].x) {
	    int l = lower_bound(ALL(ys), vec[j].y) - ys.begin();
	    int r = lower_bound(ALL(ys), vec[j].y + k) - ys.begin();

	    for (; l < r; ++l) {
		ans[cs[l]] += (vec[i].x - la[l]) * (ys[l + 1] - ys[l]);
		cs[l] += vec[j].tp;
		la[l] = vec[i].x;
	    }
	    ++j;
	}

	i = j;
    }

    rep(i, n) printf("%I64d%c", ans[i + 1], i == n - 1 ? '\n' : ' ');

    return 0;
}