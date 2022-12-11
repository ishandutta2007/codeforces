#include<bits/stdc++.h>

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

const int N = 2005;
const int L = 4e6+5;

int n,m;
bitset<N>b[N];
char s[N];
pair<int,pair<int,int> >e[L];
int fa[N];
int ed[N][2];

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

void solve(){
	n=get();m=get();
	fo(i,1,n)b[i].reset();
	fo(i,1,m){
		scanf("%s",s+1);
		fo(j,1,n)
		if (s[j]=='1')b[j][i]=1;else b[j][i]=0;
	}
	int k=0;
	fo(i,1,n)
		fo(j,i+1,n)e[++k]=make_pair(-(b[i]&b[j]).count(),make_pair(i,j));
	sort(e+1,e+1+k);
	fo(i,1,n)fa[i]=i;
	int u=0;
	fo(i,1,k){
		int x=e[i].second.first,y=e[i].second.second;
		int tx=getfather(x),ty=getfather(y);
		if (tx==ty)continue;
		ed[++u][0]=x;
		ed[u][1]=y;
		fa[tx]=ty;
	}
	bool yes=1;
	fo(i,1,m){
		int siz=0;
		fo(x,1,n)if (b[x][i])siz++;
		fo(x,1,u)if (b[ed[x][1]][i]&&b[ed[x][0]][i])siz--;
		if (siz!=1){yes=0;break;}
	}
	if (yes){
		printf("YES\n");
		fo(i,1,n-1)printf("%d %d\n",ed[i][0],ed[i][1]);
	}
	else printf("NO\n");
}

int main(){
	for(int T=get();T;T--)solve();
	return 0;
}