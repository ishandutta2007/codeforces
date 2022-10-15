#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
P a[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&a[i].F,&a[i].S);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		bool f1=false,f2=false,f3=false,f4=false;
		for(int j=0;j<n;j++)
		{
			if(a[j].F==a[i].F&&a[j].S>a[i].S) f1=true;
			if(a[j].F==a[i].F&&a[j].S<a[i].S) f2=true;
			if(a[j].F>a[i].F&&a[j].S==a[i].S) f3=true;
			if(a[j].F<a[i].F&&a[j].S==a[i].S) f4=true;
		}
		if(f1&&f2&&f3&&f4) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}