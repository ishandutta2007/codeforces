#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 300001;
int a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", a + i);

	int acc = 0;
	map <int, int> cnt;
	for(int i = 0; i < n; i ++)
	{
		cnt[a[i]] ++;
		if(cnt[a[i]] == 2)
			acc ++;
	}
	if(acc == 0)
	{
		printf("-1\n");
		return 0;
	}

	vector <pair <int, int> > ans;
	int last = 0;
	while(true)
	{
		int nxt = last - 1;
		map <int, int> tmp;
		while(true)
		{
			nxt ++;
			tmp[a[nxt]] ++;
			cnt[a[nxt]] --;
			if(cnt[a[nxt]] == 1)
				acc --;
			if(tmp[a[nxt]] == 2)
				break;
		}
		if(acc > 0)
		{
			ans.push_back(make_pair(last, nxt));
			last = nxt + 1;
		}
		else
		{
			ans.push_back(make_pair(last, n - 1));
			break;
		}
	}

	printf("%d\n", (int)ans.size());
	for(auto &p : ans)
		printf("%d %d\n", p.first + 1, p.second + 1);

	return 0;
}