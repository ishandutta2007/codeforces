#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1200200,inf=0x3f3f3f3f;
int mrk[N],prime[N],len,v[2550][2550];set<Vi>Set;
int cnt[N];int sz,dis[6555][1000];
map<Vi,int>Map;int num;Vi val[666666];map<int,int>s;
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
inline vector<int> getfac(int x){
	vector<int>res;int rec=x,now=1;
	while(mrk[x]){
		int v=mrk[x],cnt=0;while(x%v==0)x/=v,cnt++;
		res.pb(cnt);now*=cnt+1;
	}
	if(x>1){res.pb(1);now*=2;}//WA
	sort(res.begin(),res.end());cnt[rec]=now;
	return res;
}
inline int getcnt(Vi a){
	int res=1;rep(i,0,SZ(a)-1)res*=a[i]+1;return res;
}
void trans(){
	vector<Vi>a;
	for(set<Vi>::iterator it=Set.begin();it!=Set.end();it++){
		Vi x=*it;
		rep(j,0,SZ(x)-1){
			Vi y=x;y[j]++;sort(y.begin(),y.end());if(!Set.count(y))a.pb(y);
		}
	}
	per(i,SZ(a)-1,0)Set.insert(a[i]);
}
Vi e[2550];
inline void spfa(int s){
	Vi pos[2550];pos[0].pb(s);v[s][s]=0;
	rep(i,1,num)if(v[s][i]==1)pos[1].pb(i);
	rep(d,0,2000){
		if(!SZ(pos[d]))break;
		rep(t,0,SZ(pos[d])-1){
			int u=pos[d][t];
			rep(j,0,SZ(e[u])-1)if(v[s][e[u][j]]>v[s][u]+1){
				v[s][e[u][j]]=v[s][u]+1;pos[v[s][e[u][j]]].pb(e[u][j]);
			}
		}
	}
}
int main() {//freopen("1.in","r",stdin);
	getp(1e6);
	rep(i,1,1e6){
		vector<int>s=getfac(i);Set.insert(s);
	}
	rep(t,1,7)trans();//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	while(!Set.empty()){
		Vi S=*Set.begin();Set.erase(Set.begin());Map[S]=++num;val[num]=S;
		int tmp=getcnt(S);if(!s.count(tmp))s[tmp]=++sz;
	}
//	printf("<%d %d>\n",num,sz);
//	rep(i,1,10){printf("%d:",SZ(val[i]));rep(j,0,SZ(val[i])-1)printf("%d ",val[i][j]);puts("");}
//	rep(i,1,sz)printf("%d \n",s[i]);
	memset(dis,inf,sizeof(dis));memset(v,inf,sizeof(v));
	rep(i,1,num){
		Vi x=val[i];
		rep(j,0,SZ(x)-1){
			Vi y=x;y[j]--;sort(y.begin(),y.end());if(y[0]==0)y.erase(y.begin());int tmp;//WA
			if(tmp=Map[y])v[i][tmp]=v[tmp][i]=1,e[i].pb(tmp),e[tmp].pb(i);
			y=x;y[j]++;sort(y.begin(),y.end());
			if(tmp=Map[y])v[i][tmp]=v[tmp][i]=1,e[i].pb(tmp),e[tmp].pb(i);
		}
	}
	rep(i,1,num)v[i][i]=0,spfa(i);
//	rep(k,1,num)rep(i,1,num)rep(j,1,num)v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
	rep(i,1,num)rep(j,1,num)dis[i][s[getcnt(val[j])]]=min(dis[i][s[getcnt(val[j])]],v[i][j]);
	Vi d1,d2;d1.pb(1);d1.pb(2);d2.pb(5);
//	printf("[%d %d %d]\n",v[Map[d1]][Map[d2]],dis[Map[d1]][s[6]],dis[Map[d2]][s[6]]);//,getcnt(d2),getcnt(d3));
//	printf("[%d]\n",v[1][3]);
//	puts("OwO");
	int q;read(q);while(q--){
		int x,y;read(x);read(y);int res=inf;
		x=Map[getfac(x)];y=Map[getfac(y)];
		rep(i,1,sz)res=min(res,dis[x][i]+dis[y][i]);
	//	printf("[%d %d %d]\n",v[x][y],dis[x][s[6]],dis[y][s[6]]);
		printf("%d\n",res);
	}
	return 0;
}