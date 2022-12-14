#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
set<int> s;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
		s.insert(i);
	cout<<1;
	for(int j=1;j<=n;j++)
	{
		int t1;
		scanf("%d",&t1);
		s.erase(t1);
		set<int>::iterator it=s.end();
		it--;
		printf(" %d",j-(n-*it)+1);
	}
}