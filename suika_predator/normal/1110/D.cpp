#include<bits/stdc++.h>
using namespace std;
const int L=5;
class Solution {
public:
    void tran(int &x,int y)
    {
        x=max(x,y);
    }
    int maxGroupNumber(vector<int>& tiles) {
        sort(tiles.begin(),tiles.end());
        int dp[L][L][L],tmp[L][L][L];
        for(int i=0;i<L;i++)
            for(int j=0;j<L;j++)
                for(int k=0;k<L;k++)
                    dp[i][j][k]=tmp[i][j][k]=-0x3f3f3f3f;
        dp[0][0][1]=0;
        dp[0][0][0]=0;
        int n=tiles.size();
        for(int p=1;p<n;p++)
        {
//			cout<<p<<' '<<tiles[p]<<endl;
            if(tiles[p]-tiles[p-1]>1)
            {
//				cout<<"???"<<endl;
                int tans=-0x3f3f3f3f;
                for(int i=0;i<L;i++)
                    for(int j=0;j<L;j++)
                        for(int k=0;k<L;k++)
                            tans=max(tans,dp[i][j][k]);
                tran(tmp[0][0][1],tans);
            }
            else if(tiles[p]-tiles[p-1]==1)
            {
//				cout<<"diff"<<endl;
                for(int m2=0;m2<L;m2++)
                {
                    for(int m1=0;m1<L;m1++)
                    {
                        for(int m0=0;m0<L;m0++)
                        {
                            //from dp[m2][m1][m0]
                            tran(tmp[m1][m0][1],dp[m2][m1][m0]);
                            tran(tmp[m1][m0][0],dp[m2][m1][m0]);
                            if(m1&&m0)
                                tran(tmp[m1-1][m0-1][0],dp[m2][m1][m0]+1);
                        }
                    }
                }
            }
            else if(tiles[p]==tiles[p-1])
            {
                for(int m2=0;m2<L;m2++)
                {
                    for(int m1=0;m1<L;m1++)
                    {
                        for(int m0=0;m0<L;m0++)
                        {
                            //from dp[m2][m1][m0]
                            if(m0>=2)
                                tran(tmp[m2][m1][m0-2],dp[m2][m1][m0]+1);
                            if(m0<L-1)
								tran(tmp[m2][m1][m0+1],dp[m2][m1][m0]);
                            tran(tmp[m2][m1][m0],dp[m2][m1][m0]);
                            if(m2&&m1)
                                tran(tmp[m2-1][m1-1][m0],dp[m2][m1][m0]+1);
                        }
                    }
                }
            }
            else assert(0);
            for(int i=0;i<L;i++)
                for(int j=0;j<L;j++)
                    for(int k=0;k<L;k++)
                    {
 //                   	if(dp[i][j][k]>-1e9)cerr<<p<<' '<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
                    	dp[i][j][k]=tmp[i][j][k];
                        tmp[i][j][k]=-0x3f3f3f3f;
                    }
        }
        int ans=-0x3f3f3f3f;
        for(int i=0;i<L;i++)
            for(int j=0;j<L;j++)
                for(int k=0;k<L;k++)
                    ans=max(ans,dp[i][j][k]);
        return ans;
    }
}S;
vector<int> tmp;
int main()
{
//	freopen("data.txt","r",stdin);
    ios_base::sync_with_stdio(false);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		tmp.push_back(x);
	}
	cout<<S.maxGroupNumber(tmp)<<endl;
	return 0;
}