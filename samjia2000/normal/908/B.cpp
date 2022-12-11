#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 55;

char mp[N][N];
int n,m;
char s[105];
int a[105];
int l,ans;
int tr[5];
bool bz[5];
int fx[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int sx,sy;

bool check(int x,int y,int w){
	if (x<1||y<1||x>n||y>m||mp[x][y]=='#')return 0;
	if (mp[x][y]=='E')return 1;
	if (w>l)return 0;
	return check(x+fx[tr[a[w]]][0],y+fx[tr[a[w]]][1],w+1);
}

void dfs1(int x){
	if (x==4){
		if(check(sx,sy,1))ans++;
		return;
	}
	fo(i,0,3)
	if (!bz[i]){
		bz[i]=1;
		tr[x]=i;
		dfs1(x+1);
		bz[i]=0;
	}
}

int main(){
	n=get();m=get();
	fo(i,1,n)scanf("%s",mp[i]+1);
	fo(i,1,n)fo(j,1,m)if (mp[i][j]=='S')sx=i,sy=j;
	scanf("%s",s+1);
	l=strlen(s+1);
	fo(i,1,l)a[i]=s[i]-'0';
	dfs1(0);
	printf("%d\n",ans);
	return 0;
}