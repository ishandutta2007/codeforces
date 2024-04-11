#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1010;
int a[maxn], cnt, n;
bool vis[maxn], mark[maxn];
vector<int> op;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		fill(mark + 1, mark + n + 1, false);
		op.clear();
		cnt = n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] == i - 1)
			{
				mark[i] = true;
				cnt--; 
			} 
		}
		while(cnt)
		{
			int mex;
			fill(vis, vis + n + 1, false);
			for(int i = 1; i <= n; i++)
				vis[a[i]] = true;
			for(int i = 0; i <= n; i++)
				if(!vis[i])
				{
					mex = i;
					break;
				}
			if(mex == n)
			{
				for(int i = 1; i <= n; i++)
					if(!mark[i])
					{
						op.push_back(i);
						a[i] = mex;
						break;
					}
			}
			else
			{
				op.push_back(mex + 1);
				a[mex + 1] = mex;
				mark[mex + 1] = true;
				cnt--;
			}
		}
		cout << op.size() << endl;
		for(int i : op)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}