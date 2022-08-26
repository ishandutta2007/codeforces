#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr ksgkfjasdhf
#define stderr dfjgdfjkghd
#endif

#define sz(x) ((int)x.size())
#define mp(x,y) make_pair(x, y)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const double EPS = 1e-8;
const int DX[] = {1, 0, -1,  0, 1, -1,  1, -1};
const int DY[] = {0, 1,  0, -1, 1, -1, -1,  1};

const int N = 200179;

int n, m;
struct Event
{
	enum Type
	{
		LEFT = 0,
		REQ = 1,
		RIGHT = 2
	} type;
	int num;
	ll x;
	ll r;
} e[N*3];
int ec = 0;

int ans[N];

int main()
{
    ios::sync_with_stdio(false);
    
	cin >> n >> m;
	ll x1, y1, x2, y2;
	for (int i = 0; i < n; ++i)
	{
		cin >> x2 >> y2;
		if (i != 0)
		{
			e[ec].type = Event::LEFT;
			e[ec].num = i-1;
			e[ec].r = y2-x1;
			e[ec++].x = x2-y1;
			e[ec].type = Event::RIGHT;
			e[ec].num = i-1;
			e[ec++].x = y2-x1;
		}
		x1 = x2;
		y1 = y2;
	}
	for (int i = 0; i < m; ++i)
	{
		ll a;
		cin >> a;
		e[ec].type = Event::REQ;
		e[ec].num = i;
		e[ec].x = a;
		++ec;
	}
	--n;
	sort(e, e + ec, [](const Event & e1, const Event & e2) {
		if (e1.x == e2.x)
			return e1.type < e2.type;
		return e1.x < e2.x;
	});

	set < pair < ll , int > > crs;
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < ec; ++i)
	{
		if (e[i].type == Event::REQ)
		{
			if (crs.empty())
				continue;
			auto it = crs.begin();
			ans[it->second] = e[i].num;
			crs.erase(it);
		} else if (e[i].type == Event::LEFT)
			crs.insert(make_pair(e[i].r, e[i].num));
		else if (crs.find(make_pair(e[i].x, e[i].num)) != crs.end())
		{
			cout << "No\n";
			return 0;
		} else
			crs.erase(make_pair(e[i].x, e[i].num));
	}

	cout << "Yes\n";
	for (int i = 0; i < n; ++i)
		cout << ans[i]+1 << " ";
	return 0;
}