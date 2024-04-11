#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,tmp,a1,a2,cnt1,cnt2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		if(!a1)a1=tmp,cnt1++;
		else if(a1==tmp)cnt1++;
		else if(!a2) a2=tmp,cnt2++;
		else if(a2==tmp) cnt2++;
	}
	if(a1&&a2&&(cnt1+cnt2==n)&&(cnt1==cnt2))printf("YES\n%d %d\n",a1,a2);
	else printf("NO\n");
	return 0;
}