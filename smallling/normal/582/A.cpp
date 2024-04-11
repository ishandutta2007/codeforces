#include<map>
#include<cstdio>
#include<algorithm>

using namespace std;

map<int,int>cnt;
int n,a[250010],ans[510],tot;

int gcd(int a,int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	sort(a+1,a+1+n*n);
	for(int i=n*n;i;i--)
		if(cnt[a[i]])
		{
			ans[++tot]=a[i];
			cnt[a[i]]--;
			for(int j=1;j<tot;j++)
				cnt[gcd(a[i],ans[j])]-=2;
		}
	for(int i=1;i<=tot;i++)
		printf("%d ",ans[i]);
}