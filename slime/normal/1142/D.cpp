#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
#define nr 6
using namespace std;
int nx[nr][11][maxn];
char inp[maxn];
int s[maxn];
int c[11][11];
int tt[maxn], sm[maxn];
int main()
{
	for(int j = 0; j < 11; j++)
		for(int i = 0; i < 11; i++)
			if(j == 0) c[i][j] = 0;
			else c[i][j] = (i + c[(i + 1) % 11][j - 1]) % 11;
	sm[0] = 0, tt[1] = sm[1] = 9;
	//cout<<c[1][9]<<" "<<endl;
	for(int i = 2; i < nr; i++)
	{
		tt[i] = c[(sm[i - 2] + 1) % 11][tt[i - 1]];
		sm[i] = (sm[i - 1] + tt[i]) % 11;
	//	cout<<i<<" "<<tt[i]<<" "<<sm[i]<<endl;
	//	if(i >= 4) cout<<sm[i - 2] + 1<<" "<<tt[i - 1]<<endl;
	}
	scanf("%s", inp + 1);
	int n = strlen(inp + 1);
	for(int i = 1; i <= n; i++)
		s[i] = inp[i] - '0';
	for(int i = n + 1; i >= 1; i--)
		for(int j = 0; j < 11; j++)
			for(int k = 1; k < nr; k++)
			{
				if(i == n + 1)
					nx[k][j][i] = i;
				else
				{
					nx[k][j][i] = i;
					if(s[i] < (j + sm[k - 1]) % 11) 
					{
						int ed = (c[(sm[k - 1] + 1) % 11][(j + 10) % 11] + s[i] + 1) % 11;
						int nk = k + 1;
						if(k == nr - 1) nk -= 2;
						nx[k][j][i] = nx[nk][ed][i + 1];
					}
				}
			}
	//cout<<"EDN"<<endl;
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == 0) continue;
		else
		{
			int ned = nx[1][s[i]][i + 1];
			ans += ned - i;
		//cout<<i<<" "<<ned<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}