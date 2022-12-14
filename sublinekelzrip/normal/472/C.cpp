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
const int maxlongint=2147483647;
const int inf=1000000000;
struct C
{
	char a[55];
	char operator[](int i)
	{
		return a[i];
	}
};
C a[100010][2],now;
inline int cmp(C a,C b)
{
	int lena=strlen(a.a),lenb=strlen(b.a);
	int x=0;
	for(int i=0;i<min(lena,lenb);i++)
		if(a[i]<b[i])
			return 1;
		else
			if(a[i]>b[i])	
				return 0;
	if(lena<lenb)
		return 1;
	return 0;
}
int f[100010],num[100010];
int main()
{
	int n,n1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%s%s",a[n1][0].a,a[n1][1].a);
	}
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d",&num[n1]);
		f[n1]=num[n1];
	}
	if(cmp(a[f[1]][0],a[f[1]][1]))
		now=a[f[1]][0];
	else
		now=a[f[1]][1];
	for(n1=2;n1<=n;n1++)
	{
		if(cmp(a[f[n1]][0],a[f[n1]][1]))
			if(cmp(now,a[f[n1]][0]))
				now=a[f[n1]][0];
			else
				if(cmp(now,a[f[n1]][1]))
					now=a[f[n1]][1];
				else
				{
					cout<<"NO";
					return 0;
				}
		else
			if(cmp(now,a[f[n1]][1]))
				now=a[f[n1]][1];
			else
				if(cmp(now,a[f[n1]][0]))
					now=a[f[n1]][0];
				else
				{
					cout<<"NO";
					return 0;
				}	
	}
	cout<<"YES";
}