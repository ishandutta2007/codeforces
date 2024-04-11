#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1; char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
typedef long long ll;
const int M = 100016, MOD = 1000000007;

int dp[256][256][8][8]; //0x3f
pair<int,int> tr[256][256][8][8]; 
int solve(int i, int j, int k, int l)
{
	if(i<0 || j<0) return -10000;
	int &res = dp[i][j][k][l];
	if(res==0x3f3f3f3f) 
	{
		res = -10000;
		if(k>=3 && (l==3 || l==k-3)) //
		{
			if(i==0 && j==0) res = 0;
		}
		else
		{
			int upp = (k==4?15:25);
			for(int x=0; x<upp-2; ++x)
			{
				int tmp = 1 + solve(i-upp, j-x, k+1, l+1);
				if(res < tmp) tr[i][j][k][l] = {upp,x}, res = tmp;
				tmp = -1 + solve(i-x, j-upp, k+1, l);
				if(res < tmp) tr[i][j][k][l] = {x,upp}, res = tmp;
			}
			for(int x=upp; x<=max(i,j); ++x)
			{
				int tmp = 1 + solve(i-x, j-(x-2), k+1, l+1);
				if(res < tmp) tr[i][j][k][l] = {x,x-2}, res = tmp;
				tmp = -1 + solve(i-(x-2), j-x, k+1, l);
				if(res < tmp) tr[i][j][k][l] = {x-2,x}, res = tmp;
			}
		}
	}
	return dp[i][j][k][l];
}
int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif

	memset(dp, 0x3f, sizeof(dp));
	for(int i=0; i<=200; ++i)
		for(int j=0; j<=200; ++j)
			solve(i, j, 0, 0);
	int q = read();
	while(q--)
	{
		int a = read(), b = read();
		int res = dp[a][b][0][0];
		if(res<-3)
		{
			printf("Impossible\n");
		}
		else
		{
			int k=0, l=0;
			printf("%d:%d\n",res>0?3:res+3, res<0?3:3-res );
			for(int i=0; ; ++i)
			{
				pair<int,int> tp = tr[a][b][k][l];
				printf("%d:%d ",tp.first,tp.second );
				a -= tp.first, b-=tp.second;
				++k;
				if(tp.first>tp.second) ++l;
				if(k>=3 && (l==3 || l==k-3)) break;
			}
			printf("\n");
		}
	}


	return 0;
}