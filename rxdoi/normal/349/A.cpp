#include<cstdio>
using namespace std;

int cnt[4],n,x;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&x);
		x/=25;
		if (x==2&&!cnt[1]) {puts("NO");return 0;}
		if (x==4&&cnt[1]<3&&!(cnt[1]>=1&&cnt[2]>=1)) {puts("NO");return 0;}
		if (x==1) cnt[1]++;
		if (x==2) cnt[1]--,cnt[2]++;
		if (x==4) 
			if (cnt[1]>=1&&cnt[2]>=1) cnt[1]--,cnt[2]--;else cnt[1]-=3;
	}
	puts("YES");
}