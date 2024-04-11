#include<cstdio>
using namespace std;

const int Maxn=400+19;
int s[Maxn][Maxn],Q[Maxn];
int n,m,k,dl,dr;
long long Ans,cnt[26],tmp;
char c[Maxn][Maxn];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%s",c[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) s[i][j]=s[i][j-1]+(c[i][j]=='a');
	for (int L=1;L<=m;L++)
		for (int R=L+1;R<=m;R++)
		{
			dl=dr=tmp=0;
			for (int i=0;i<26;i++) cnt[i]=0;
			for (int x=1;x<=n;x++)
			{
				tmp+=s[x][R]-s[x][L-1];
				Q[++dr]=x;
				if (c[x][L]!=c[x][R]) continue;
				while (dl+1<dr&&tmp>k) 
				{
					dl++;
					tmp-=s[Q[dl]][R]-s[Q[dl]][L-1];
					if (c[Q[dl]][L]==c[Q[dl]][R]) cnt[c[Q[dl]][L]-'a']--;
				}
				Ans+=cnt[c[x][R]-'a'];
				cnt[c[x][R]-'a']++;
			}
		}
	printf("%I64d\n",Ans);
}