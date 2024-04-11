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
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num[105];
int main()
{
	int n,m,t,n1,n2;
	cin>>n>>m;
	for(n1=1;n1<=m;n1++)
	{
		cin>>t;
		for(n2=t;n2<=n;n2++)
			if(num[n2]==0)
				num[n2]=t;
	}
	for(n1=1;n1<=n;n1++)
		cout<<num[n1]<<' ';
}