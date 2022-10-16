#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 80
using namespace std;
int dp[maxn][maxn][maxn][3]; //  V K 
char inp[maxn];
int tp[maxn];
 
int main()
{
	int len;
	scanf("%d", &len);
	scanf("%s", inp + 1);
	int cnt[3] = {0, 0, 0};
	for(int i = 1; i <= len; i++)
		if(inp[i] == 'V') tp[i] = 0, cnt[0]++;
		else if(inp[i] == 'K') tp[i] = 1, cnt[1]++;
		else tp[i] = 2;
	cnt[2] = len - cnt[0] - cnt[1];
//	cout<<"!!!"<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
	for(int i = len; i >= 1; i--)
		for(int j = 0; j <= len - i + 1 && j <= cnt[0]; j++)
			for(int k = 0; k <= len - i + 1 && k <= cnt[1]; k++)
				for(int l = 0; l < 3; l++)
				{
					dp[i][j][k][l] = maxn * maxn * maxn * maxn;
					int cnt3 = len - i + 1 - j - k;
					if(cnt3 < 0 || cnt3 > cnt[2]) 
						continue;
					for(int s = 0; s < 3; s++)
					{
						if(s == 1 && l == 0) continue;
						if(s == 0 && !j) continue;
						if(s == 1 && !k) continue;
						if(s == 2 && !cnt3) continue;
					
						int nans = 0;
						if(s == 0) nans = dp[i + 1][j - 1][k][s];
						else if(s == 1) nans = dp[i + 1][j][k - 1][s];
						else nans = dp[i + 1][j][k][s];	
						int uscnt[3] = {cnt[0] - j, cnt[1] - k, cnt[2] - cnt3};
						//cout<<s<<" "<<uscnt[s]<<" "<<cnt[s]<<endl;
						uscnt[s]++;
						int lst = 0;
						for(int m = 1; m <= len; m++)
						{
							if(uscnt[tp[m]])
								uscnt[tp[m]]--;
							else lst++;
							if(!uscnt[s]) break;
						}
						nans += lst;
						dp[i][j][k][l] = min(dp[i][j][k][l], nans);
					}
				//	cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;
				}
	printf("%d\n", dp[1][cnt[0]][cnt[1]][2]);
	return 0;
}