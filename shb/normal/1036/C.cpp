#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int digit[100],len;
LL f[110][10][2];

LL solve(int x,int cnt,bool up)
{
	if (cnt > 3) return 0;
	if (f[x][cnt][up] != -1) return f[x][cnt][up];
	if (x == len + 1) return 1;
	LL ret = 0;
	int mv = (up?digit[x]:9);
	for (int i=0;i<=mv;i++)
	{
		ret += solve(x+1,cnt + (i!=0), up && (i==digit[x]));
	}
	return f[x][cnt][up] = ret;
}

LL calc(LL x)
{
	len = 0;
	do
	{
		digit[++len] = x % 10;
		x /= 10;
	}while(x);
	reverse(digit+1,digit+len+1);
	memset(f,-1,sizeof(f));
	return solve(0,0,1);
}

int main()
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		LL L,R;
		scanf("%lld%lld",&L,&R);
		printf("%lld\n",calc(R) - calc(L - 1));
	}
}