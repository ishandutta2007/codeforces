#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;
const int M=5000000;
const int oo=(1<<29)-1;

struct info{
	int mx;
	ll cnt;
	void operator += (const info &B){
		if (B.mx>mx) mx=B.mx,cnt=B.cnt;
		lf (B.mx==mx) cnt+=B.cnt;
	}
} ans;

struct Edge{
	int y,nxt;
} E[M];
char s[N];
int las[N],bit[N],sum[2048],dis2[2048][2048];
int dis[8][N],vis[8];
int n,cnt;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void bfs(int c){
	static int Q[N];
	int *dis=::dis[c],f=0,w=0;
	For(i,0,N) dis[i]=oo;
	For(i,1,n+1)
		if (s[i]-'a'==c){
			Q[++f]=i;
			dis[i]=0;
		}
	For(i,0,8) vis[i]=0;
	vis[c]=1;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (dis[y=E[i].y]==oo){
				dis[y]=dis[x]+1;
				Q[++f]=y;
			}
		if (!vis[s[x]-'a']){
			vis[s[x]-'a']=1;
			For(i,1,n+1) if (s[i]==s[x]&&dis[i]==oo){
				dis[i]=dis[x]+1;
				Q[++f]=i;
			}
		}
	}
	For(i,1,n+1){
		dis[s[i]-'a'+n+1]=min(dis[s[i]-'a'+n+1],dis[i]);
	}
}
void Main(){
	memset(las,-1,sizeof(las));
	memset(sum,0,sizeof(sum));
	cnt=0;
	ans=(info){-1,0};
	n=IN();
	scanf("%s",s+1);
	For(i,1,n) Link(i,i+1);
	For(i,0,8) bfs(i);
	For(i,1,n+1){
		int w=0;
		For(j,0,8){
			w|=(dis[j][i]-dis[j][s[i]-'a'+n+1])<<j;
		}
		bit[i]=(s[i]-'a')<<8|w;
	}
	For(i,0,2048) For(j,0,2048){
		dis2[i][j]=oo;
		For(k,0,8){
			dis2[i][j]=min(dis2[i][j],dis[k][(i>>8)+n+1]+dis[k][(j>>8)+n+1]+(i>>k&1)+(j>>k&1)+1);
		}
	}
	For(i,1,n+1){
		For(j,max(i-20,1),i){
			int d=i-j;
			For(k,0,8) d=min(d,dis[k][i]+dis[k][j]+1);
			ans+=(info){d,1};
		}
		if (i-21>=1){
			For(j,1,i-20){
				int d=oo;
				For(k,0,8) d=min(d,dis[k][i]+dis[k][j]+1);
			}
			For(k,0,2048) if (sum[k]){
				ans+=(info){dis2[bit[i]][k],sum[k]};
			}
		}
		if (i-20>=1) sum[bit[i-20]]++;
	}
	cout<<ans.mx<<" "<<ans.cnt<<endl;
}

int main(){
	Main();
//	for (int T=IN();T--;) Main();
}