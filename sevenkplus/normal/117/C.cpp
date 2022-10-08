#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
int n;bitset<5000> a[5010];int v[5010];int fa[5010],T=-1;vector<int> b;
void ff(int x)
{
	if(T!=-1)return;
	v[x]=1;
	for(int i=0;i<n;i++)if(a[x][i])
		if(v[i]==1){fa[i]=x,T=x;break;}else
		if(!v[i])fa[i]=x,ff(i);
	v[x]=2;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char s[10000];
		scanf("%s",s);
		for(int j=0;j<n;j++)if(s[j]=='1')a[i].set(j);
	}
	for(int i=0;i<n;i++)if(v[i]==0){ff(i);}
	if(T==-1){puts("-1");return 0;}
	b.push_back(T);
	for(int U=fa[T];U!=T;U=fa[U])b.push_back(U);
	reverse(b.begin(),b.end());
	for(int i=0;i<(int)b.size();i++)
	{
		int x=b[i],y=b[(i+1)%(int)b.size()];
		for(int j=0;j<n;j++)
			if(a[j][x]&&a[y][j]){printf("%d %d %d\n",j+1,x+1,y+1);return 0;}
	}
	return 0;
}