#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long intl;
map <int, vector <pair <int, int> > > mp[2];

struct Event
{
	int pos;
	int type;
	int s, t;
	Event(int pos, int s, int t, int type) : pos(pos), s(s), t(t), type(type) { }
	bool operator <(const Event &rhs) const
	{
		if(pos == rhs.pos)
			return abs(type) > abs(rhs.type);
		return pos < rhs.pos;
	}
};

map <int, int> disc;

void pre_process(vector <pair <int, int> > &vec, int pos, int type, vector <Event> &events, intl &cnt)
{
	for(auto &p : vec)
	{
		if(p.first > p.second)
			swap(p.first, p.second);
		p.second ++;
	}
	sort(vec.begin(), vec.end());
	vector <pair <int, int> > ans;
	int start = vec[0].first;
	int last = vec[0].second;
	for(auto &p : vec)
		if(p.first <= last)
			last = max(last, p.second);
		else
		{
			ans.push_back(make_pair(start, last));
			start = p.first;
			last = p.second;
		}
	ans.push_back(make_pair(start, last));
	//vec = ans;
	for(auto &p : ans)
	{
		if(type == 0)
		{
			events.push_back(Event(p.first, pos, pos + 1, 1));
			events.push_back(Event(p.second, pos, pos + 1, -1));
		}
		else
			events.push_back(Event(pos, p.first, p.second, 0));
		disc[pos] = disc[p.first] = disc[p.second] = 1;
		cnt += p.second - p.first;
	}
}

const int N = 801111;
int lowbit(int x)
{
	return x & (-x);
}
struct BIT
{
	int b[N];
	BIT() { }
	void change(int pos, int x)
	{
		pos += 2;
		for(int i = pos; i < N; i += lowbit(i))
			b[i] += x;
	}
	int query(int pos)
	{
		pos += 2;
		int ret = 0;
		for(int i = pos; i > 0; i -= lowbit(i))
			ret += b[i];
		return ret;
	}
}bit;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;	
		if(x1 == x2)
		{
			if(mp[0].find(x1) == mp[0].end())
				mp[0][x1] = vector <pair <int, int> > ();
			mp[0][x1].push_back(make_pair(y1, y2));
		}
		else
		{
			if(mp[1].find(y1) == mp[1].end())
				mp[1][y1] = vector <pair <int, int> > ();
			mp[1][y1].push_back(make_pair(x1, x2));
		}
	}
	intl ans = 0;
	vector <Event> events;
	for(int i = 0; i < 2; i ++)
		for(auto it = mp[i].begin(); it != mp[i].end(); it ++)
			pre_process(it -> second, it -> first, i, events, ans);

	int disc_cnt = 0;
	for(auto it = disc.begin(); it != disc.end(); it ++)
		it -> second = disc_cnt ++;
	/*
	for(auto it = disc.begin(); it != disc.end(); it ++)
		it -> second = it -> first + 3000;
	*/
	sort(events.begin(), events.end());
	for(auto &eve : events)
	{
		//cout << eve.pos << ' ' << eve.type << ' ' << eve.s << ' ' << eve.t << '\n';
		if(eve.type == 0)
			ans -= bit.query(disc[eve.t] - 1) - bit.query(disc[eve.s] - 1);
		else
			bit.change(disc[eve.s], eve.type);
	}
	cout << ans << '\n';
	return 0;
}