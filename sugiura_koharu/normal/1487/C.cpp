#include <iostream>
#include <cstring>
using namespace std;
int ans[105][105],W[105],qwq[105];
int main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		memset(W,0,sizeof W);
		memset(qwq,0,sizeof qwq);
		cin >> n;
		if(n==0)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n;j++) ans[i][j]=-1,++qwq[j];
				if(i%2==1)
				{
					ans[i][i+1]=0,--qwq[i+1];
					for(int j=i+2;j<=i+n/2-qwq[i]+1;j++)
						ans[i][j]=1,--qwq[j];
				}
				else
				{
					for(int j=i+2;j<=i+n/2-qwq[i]+1;j++)
						ans[i][j]=1,--qwq[j];
				}
			}
		}
		else if(n%2==0)
		{
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[i][j]=2;
			for(int i=1;i<=n;i+=2)
			{
				ans[i][i+1]=ans[i+1][i]=0;
				for(int j=i+2;j<=n;j+=2) ans[i][j]=1;
				for(int j=i+3;j<=n;j+=2) ans[i][j]=-1;
				for(int j=i+2;j<=n;j+=2) ans[i+1][j]=-1;
				for(int j=i+3;j<=n;j+=2) ans[i+1][j]=1;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=i+n/2;j++)
					ans[i][j]=1;
				for(int j=i+n/2+1;j<=n;j++)
					ans[i][j]=-1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cout << ans[i][j] << " ";
				if(ans[i][j]==1) W[i]+=3;
				if(ans[i][j]==-1) W[j]+=3;
				if(ans[i][j]==0) W[i]+=1,W[j]+=1;
			}
		}
		cout << "\n";
	//	for(int i=1;i<=n;i++) cerr << W[i] << " ";
	//	cerr << "\n";
	}
	return 0;
}