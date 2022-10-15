#include<bits/stdc++.h>
#define MAXN 5005
#define MAXM 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,now;
string str[MAXN];
int save[MAXN][4];//type,operand,operation,operand
//0:AND 1:OR 2:XOR
int num[MAXN][MAXM];
int res[MAXN];
int ans[2][MAXM];
unordered_map<string,int> mp;
int find_res(int k,int id)
{
	if(res[id]!=-1) return res[id];
	if(save[id][0]==0) return res[id]=num[id][k];
	int l,r;
	if(save[id][1]==n) l=now;
	else l=find_res(k,save[id][1]);
	if(save[id][3]==n) r=now;
	else r=find_res(k,save[id][3]);
	if(save[id][2]==0) return res[id]=(l&r);
	else if(save[id][2]==1) return res[id]=(l|r);
	else if(save[id][2]==2) return res[id]=(l^r);
}
int main()
{
	scanf("%d%d",&n,&m);
	getchar();
	memset(num,0,sizeof(num));
	mp.clear();
	for(int i=0;i<n;i++)
	{
		getline(cin,str[i]);
		for(int j=0;;j++)
		{
			if(str[i][j]==':')
			{
				mp[str[i].substr(0,j-1)]=i;
				int t=j+3;
				if(str[i][t]=='0'||str[i][t]=='1') 
				{
					save[i][0]=0;
					for(int k=0;k<m;k++)
						num[i][k]=str[i][t+k]-'0';
					break;
				}
				save[i][0]=1;
				if(str[i][t]=='?') {save[i][1]=n; t++;}
				else
				{
					while(str[i][t]!=' ') t++;
					save[i][1]=mp[str[i].substr(j+3,t-j-3)];
				}
				t++;
				if(str[i][t]=='A') {save[i][2]=0; t+=4;}
				else if(str[i][t]=='O') {save[i][2]=1; t+=3;}
				else {save[i][2]=2; t+=4;}
				if(str[i][t]=='?') save[i][3]=n; else save[i][3]=mp[str[i].substr(t)];
				break;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		memset(res,-1,sizeof(res));
		now=0;
		int t1=0,t2=0;
		for(int j=0;j<n;j++)
			if(res[j]==-1) find_res(i,j);
		for(int j=0;j<n;j++)
			t1+=res[j];
		memset(res,-1,sizeof(res));
		now=1;
		for(int j=0;j<n;j++)
			if(res[j]==-1) find_res(i,j);
		for(int j=0;j<n;j++)
			t2+=res[j];
		if(t2>t1) {ans[0][i]=0; ans[1][i]=1;}
		else if(t2<t1) {ans[0][i]=1; ans[1][i]=0;}
		else ans[0][i]=ans[1][i]=0;
	}
	for(int i=0;i<m;i++)
		printf("%d",ans[0][i]);
	puts("");
	for(int i=0;i<m;i++)
		printf("%d",ans[1][i]);
	return 0;
}