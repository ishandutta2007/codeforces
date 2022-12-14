# include <iostream>
# include <map>
# include <string>
# include <cstdio>
# include <queue>
# include <fstream>
using namespace std;
int a[1000];
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int x,y;
	cin>>x>>y;
	int now=1;
	int sum_beg=0;
	bool p=0;
	while (now<=n)
	{
		if (sum_beg>=x && sum_beg<=y && sum-sum_beg<=y && sum-sum_beg>=x)
		{
			cout<<now<<endl;
			p=1;
			break;
		}
		sum_beg+=a[now];
		now++;
	}
	if (p==0)
	cout<<0<<endl;
}