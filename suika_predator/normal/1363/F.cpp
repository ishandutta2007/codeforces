#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[2333],t[2333];
int cnt[2333][33],cnt2[2333][33];
int f[2333][2333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(f[0],0x3f,sizeof(f[0]));
		cin>>n;
		cin>>(s+1)>>(t+1);
		for(int i=1;i<=n;i++)
		{
			memset(f[i],0x3f,sizeof(f[i]));
			for(char ch='a';ch<='z';ch++)
			{
				cnt[i][ch-'a']=cnt[i-1][ch-'a']+(s[i]==ch);
				cnt2[i][ch-'a']=cnt2[i-1][ch-'a']+(t[i]==ch);
			}
		}
		int ok=1;
		for(char ch='a';ch<='z';ch++)
		{
			if(cnt[n][ch-'a']!=cnt2[n][ch-'a'])
			{
				ok=0;
				break;
			}
		}
		if(!ok){cout<<-1<<endl;continue;}
		f[0][0]=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(s[i+1]==t[j+1])
					f[i+1][j+1]=min(f[i][j],f[i+1][j+1]);
				f[i+1][j]=min(f[i][j]+1,f[i+1][j]);
//				cerr<<i<<' '<<j<<' '<<t[j+1]<<' '<<cnt[i][t[j+1]-'a']<<' '<<cnt2[j+1][t[j+1]-'a']<<endl;
				if(cnt[i][t[j+1]-'a']<cnt2[j+1][t[j+1]-'a'])
					f[i][j+1]=min(f[i][j],f[i][j+1]);
			}
		}
//		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)cerr<<i<<' '<<j<<' '<<f[i][j]<<endl;
		cout<<f[n][n]<<endl;
	}
	return 0;
}