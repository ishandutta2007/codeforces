#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n, limit;
	//cin >> n >> limit;
	scanf("%d%d", &n, &limit);
	map <int, int> mp;
	map <int, int> mp_add;
	//map <int, int> mp_sub;
	for(int i = 0; i < n; i ++)
	{
		int a, b;
		//cin >> a >> b;
		scanf("%d%d", &a, &b);
		mp[a] ++;
		mp[b] --;
		mp_add[a] ++;
		//mp_sub[b] ++;
	}
	int last;
	int k = 0;
	vector <pair <int, int> > ans;
	for(auto it = mp.begin(); it != mp.end(); it ++)
	{
		if(k < limit && k + (it -> second) >= limit)
			last = it -> first;
		else if(k >= limit && k + (it -> second) < limit)
			ans.push_back(make_pair(last, it -> first));
		else if(k < limit && k + (it -> second) < limit && k + mp_add[it -> first] >= limit)
			ans.push_back(make_pair(it -> first, it -> first));
		k += it -> second;
	}
	//cout << ans.size() << '\n';
	printf("%d\n", (int)ans.size());
	for(auto &p : ans)
		//cout << p.first << ' ' << p.second << '\n';
		printf("%d %d\n", p.first, p.second);
	return 0;
}