#include<bits/stdc++.h>
#define MAXN 300005
#define F first
#define S second
using namespace std;
typedef long long ll;
struct save
{
	int F,S,id;
};
bool cmp(save x,save y)
{
	if(x.F!=y.F) return x.F<y.F;
	return x.S<y.S;
}
int n,T;
save a[MAXN];
bool C(int x)
{
	int cnt=0,s=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].S>=x) 
		{
			cnt++;
			s+=a[i].F;
		}
		if(cnt==x&&s<=T) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].S,&a[i].F);
		a[i].id=i+1;
	}
	sort(a,a+n,cmp);
	int l=0,r=n+1;
	while(r-l>1)
	{
		int mid=(l+r)/2;
		if(C(mid)) l=mid;  else r=mid;
	}
	if(l==0) {printf("0\n0\n"); return 0;}
	printf("%d\n%d\n",l,l);
	int cnt=l;
	for(int i=0;i<n;i++)
	{
		if(a[i].S>=l) 
		{
			cnt--;
			printf("%d ",a[i].id);
		}
		if(cnt==0) break;
	}
	return 0;
}