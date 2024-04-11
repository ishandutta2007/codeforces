#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

const int N = 2007;

string s[N];
short used[N][N];
pair<int, int> from[N][N];
vector<pair<int, int> > v;

struct d
{
	int x, y, t;
	int prx, pry;
};

struct  cmp
{
	bool operator()(d p1, d p2)const
	{
		return p1.t > p2.t;
	}
};

int n, k;
int curr_maxi = -1;

void dijkstra()
{
	priority_queue<d , vector<d>, cmp> q;
	d d1;

	d1.x = 0;
	d1.y = 0;
	d1.t = 0;
	d1.prx = -1;
	d1.pry = -1;

	q.push(d1);

	while(!q.empty())
	{
		int x = q.top().x, y= q.top().y, t = q.top().t;
		int prx = q.top().prx, pry = q.top().pry;
		q.pop();

		if(used[x][y] == 2)
			continue;

		//cout << x << " " << y << "  t "<< t << endl;

		used[x][y] = 2;
		from[x][y] = {prx, pry};

		if(t == k || (x == n-1 && y == n-1 && v.empty()))
		{
			if(x+y > curr_maxi)
			{
				curr_maxi = x+y;
				v.clear();
				v.push_back({x, y});
			}
			else
				if(x+y == curr_maxi)
					v.push_back({x, y});
			continue;
		}

		if(x < n-1 && !used[x+1][y])
		{
			d1.x = x+1;
			d1.y = y;
			d1.prx = x;
			d1.pry = y;


			if(s[x+1][y] == 'a')
				d1.t = t;
			else
				d1.t = t+1;

			q.push(d1);
		}
		if(y < n-1 && !used[x][y+1])
		{
			d1.x = x;
			d1.y = y+1;
			d1.prx = x;
			d1.pry = y;


			if(s[x][y+1] == 'a')
				d1.t = t;
			else
				d1.t = t+1;

			q.push(d1);
		}

	}
}

bool used2[N][N];

void bfs()
{
	int i = 0;

	queue<pair<int, int> > q;
	queue<pair<int, int> > q2;

	char best = 'z' + 1;

	for(; i < v.size(); i++)
	{
		
		
		//cout << v[i].first << " " << v[i].second << endl;

		if(s[v[i].first][v[i].second] < best)
		{
			while(!q.empty())
				q.pop();
			q.push(v[i]);
			best = s[v[i].first][v[i].second];
			used2[v[i].first][v[i].second] = true;
		}
		else
			if(s[v[i].first][v[i].second] == best)
			{
				q.push(v[i]);
				used2[v[i].first][v[i].second] = true;
			}
	}

	best = 'z' + 1;

	bool stop = false;

	while(!stop)
	{
		while(!q.empty())
		{
			pair<int, int> p = q.front();
			q.pop();

			if(p.first == n-1 && p.second == n-1)
			{
				stop = true;
				break;
			}

			if(p.first < n-1 && !used2[p.first+1][p.second])
			{
				from[p.first+1][p.second] = {p.first, p.second};
				used2[p.first+1][p.second] = true;

				if(s[p.first+1][p.second] < best)
				{
					best = s[p.first+1][p.second];
					while(!q2.empty())
						q2.pop();
					q2.push({p.first+1, p.second});
				}
				else
					if(s[p.first+1][p.second] == best)
						q2.push({p.first+1, p.second});
			}
			if(p.second < n-1 && !used2[p.first][p.second+1])
			{
				from[p.first][p.second+1] = {p.first, p.second};
				used2[p.first][p.second+1] = true;

				if(s[p.first][p.second+1] < best)
				{
					best = s[p.first][p.second+1];
					while(!q2.empty())
						q2.pop();
					q2.push({p.first, p.second+1});
				}
				else
					if(s[p.first][p.second+1] == best)
						q2.push({p.first, p.second+1});
			}
		}
		
		//cout << best << endl;

		if(!stop)
		{
			q = q2;
			while(!q2.empty())
				q2.pop();
			best = 'z' + 1;
		}

		//cout << "hi" << endl;
	}
}

string res = "";

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> s[i];

	dijkstra();
	bfs();

	int x = n-1, y = n-1;

	while(x >= 0)
	{
		res += s[x][y];
		int x2 = x, y2 = y;

		x = from[x2][y2].first;
		y = from[x2][y2].second;
	}

	reverse(res.begin(), res.end());

	for(int i = 0; i < res.size() && k; i++)
		if(res[i] != 'a')
		{
			res[i] = 'a';
			k--;
		}

	cout << res << "\n";

	return 0;
}
// premahni n-1, n-1