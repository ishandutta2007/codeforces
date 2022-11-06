#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	int a;
	int cnt[100001];
	for(int i=0;i<m;i++)
	{
		cin>>a;
		++cnt[a];
	}
	int minx = INT_MAX;
	for(int i=1;i<=n;i++) minx = min(minx, cnt[i]);
	cout<<minx<<endl;
	return 0;
}//