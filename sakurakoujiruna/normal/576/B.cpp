#include <iostream>
#include <vector>
using namespace std;

const int N = 100011;
int p[N];
bool vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];

	int vid1 = -1;
	int vid2 = -1;
	int even_cnt = 0;
	vector <vector <int> > vec;
	for(int i = 1; i <= n; i ++)
		if(!vis[i])
		{
			vector <int> tmp;
			for(int cur = i; !vis[cur]; cur = p[cur])
			{
				tmp.push_back(cur);
				vis[cur] = true;
			}
			if(tmp.size() == 2)
				vid2 = vec.size();
			else if(tmp.size() == 1)
				vid1 = vec.size();
			if(tmp.size() % 2 == 0)
				even_cnt ++;
			vec.push_back(tmp);
		}

	if(vid1 != -1)
	{
		cout << "YES\n";
		int core = vec[vid1][0];
		for(int i = 1; i <= n; i ++)
			if(i != core)
				cout << i << ' ' << core << '\n';
	}
	else if(vid2 != -1 && vec.size() == even_cnt)
	{
		int core[2] = {vec[vid2][0], vec[vid2][1]};
		cout << "YES\n";
		cout << core[0] << ' ' << core[1] << '\n';
		for(auto &v : vec)
		{
			if(v[0] == core[0] || v[0] == core[1])
				continue;
			for(int i = 0; i < v.size(); i ++)
				cout << v[i] << ' ' << core[i & 1] << '\n';
		}
	}
	else
		cout << "NO\n";

	return 0;
}