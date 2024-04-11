# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<cstdlib>
using namespace std;
int main()
{
	int a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	string s;
	cin>>s;
	long long ans=0;
	int n=s.length();
	for (int i=0;i<n;i++)
	{
		ans+=a[int(s[i])-49];
	}
	cout<<ans<<endl;
}