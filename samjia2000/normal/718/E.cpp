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

const int N = 100020;
const int L = 270;
const int INF = 1e8;

int n;
char s[N];
int dis1[N][10],dis2[10][10];
struct edge{
	int x,l,nxt;
}e[N*4];
int h[N],tot;
int que[N];
bool pd[N];
int res[N];
int ext[10][L];
int he,ta;
int S,tmp;
int v[N][17],val[N],cnt[N];

void inse(int x,int y,int l){e[++tot].x=y;e[tot].l=l;e[tot].nxt=h[x];h[x]=tot;}

void dfs(int x){
	dis1[x][S]=tmp;
	que[++ta]=x;
	for(int p=h[x];p;p=e[p].nxt)
	if (e[p].l==0&&dis1[e[p].x][S]==INF)dfs(e[p].x);
}

int main(){
	{
		n=get();
		scanf("%s",s+1);
		tot=0;
		fo(i,1,n+8)h[i]=0;
		fo(i,1,n){
			if (i>1)inse(i,i-1,1);
			if (i<n)inse(i,i+1,1);
			inse(n+1+s[i]-'a',i,0);
			inse(i,n+1+s[i]-'a',1);
		}
		int len=n+8;
		fo(st,1,8){
			S=st;
			fo(i,1,n+8)dis1[i][st]=INF;
			he=0,ta=1;
			dis1[n+st][st]=0;
			pd[que[1]=n+st]=1;
			while(he!=ta){
				int x=que[he=he%len+1];
				for(int p=h[x];p;p=e[p].nxt)
				if (dis1[e[p].x][st]>dis1[x][st]+e[p].l){
					tmp=dis1[x][st]+e[p].l;
					dfs(e[p].x);
				}
			}
		}
		fo(i,1,8)fo(j,1,8)dis2[i][j]=INF;
		fo(i,1,n)fo(j,1,8)dis2[s[i]-'a'+1][j]=min(dis2[s[i]-'a'+1][j],dis1[i][j]);
		fo(i,1,n){
			res[i]=0;
			fo(j,1,8)
			if (dis1[i][j]>dis2[s[i]-'a'+1][j])res[i]=res[i]+(1<<(j-1));
		}
		fo(i,1,8)fo(j,0,255)ext[i][j]=0;
		int dw=INF;
		fo(i,1,n)val[i]=cnt[i]=0;
		fd(i,n,1){
			fo(x,1,8)
				fo(y,0,255)
				if (ext[x][y]){
					int d=INF;
					fo(c,1,8)
					if ((y&(1<<(c-1)))==0)d=min(d,dis1[i][c]+1+dis2[c][x]);
					else d=min(d,dis1[i][c]+2+dis2[c][x]);
					if (d>val[i])val[i]=d,cnt[i]=ext[x][y];
					else if (d==val[i])cnt[i]=cnt[i]+ext[x][y];
				}
			fo(x,1,min(15,n-i)){
				v[i][x]=x;
				fo(c,1,8)v[i][x]=min(v[i][x],dis1[i][c]+1+dis1[i+x][c]);
			}
			if (i+15<=n)ext[s[i+15]-'a'+1][res[i+15]]++;
		}
		fo(ans,1,15){
			bool ck=1;
			LL ct=0;
			fd(i,n-ans,1){
				int len=val[i],tmp=cnt[i];
				fo(j,ans,min(n-i,15)){
					if (v[i][j]>len)len=v[i][j],tmp=1;
					else if (v[i][j]==len)tmp++;
				}
				if (len>ans)ck=0;
				if (len==ans)ct=ct+tmp;
			}
			if (ck){printf("%d %I64d\n",ans,ct);break;}
		}
	}
	return 0;
}