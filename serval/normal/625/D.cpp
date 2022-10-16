#include <cstdio>
using namespace std;
int main()
{
	char s[100005];
	int n,l,r;
	while ((scanf("%c",&s[++n])==1)&&(s[n]>='0')&&(s[n]<='9'))
		s[n]-='0';
	l=1;
	r=--n;
	if (s[l]!=s[r])
	{
		s[l]--;
		s[l+1]+=10;
		if (s[l]==0)
			l++;
	}
	while (l<=r)
	{
		if (s[l]!=s[r])
		{
			if ((s[l]-s[r]>=10)&&(s[r]<10))
			{
				s[r-1]--;
				s[r]+=10;
			}
			if (s[l]-s[r]==1)
			{
				s[l]--;
				s[l+1]+=10;
			}
		}
		if (s[l]!=s[r])
			break;
		if (l!=r)
		{
			s[l]=s[l]-(s[r]>>1);
			s[r]>>=1;
		}
		else
			if (((s[l]>>1)<<1)==s[l])
				s[l]>>=1;
			else
				break;
		if (s[l]>9||s[l]<0||s[r]>9||s[r]<0)
			break;
		l++;
		r--;
	}
	if (l<=r)
	{
		printf("0");
		return 0;
	}
	l=1;
	if (s[l]==0)
		l++;
	while (l<=n)
	{
		printf("%d",s[l]);
		l++;
	}
	return 0;
}