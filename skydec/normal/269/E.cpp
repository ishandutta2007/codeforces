#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=410000;
bool zhuan;int n,m;int ans[MAXN];
int dui[MAXN],std_dui[MAXN];int S,now,jian;
int fail[MAXN];int line[MAXN],id[MAXN];int N;bool vis[MAXN];
int a[MAXN],b[MAXN];
inline void wei(){
	printf("No solution\n");
	exit(0);
}
inline int getreal(char a,int x){
	if(zhuan){
		if(a=='L')a='T';
		else if(a=='R')a='B';
		else if(a=='B')a='R';
		else a='L';
	}
	if(a=='T')return x;
	if(a=='B')return x+m;
	if(a=='L')return 2*m+x;
	return 2*m+n+x;
}
inline int type(char a,char b){
	if(a=='L'){
		if(b=='R')wei();
		if(b=='T')return 1;
		else return 3;
	}
	if(a=='R'){
		if(b=='L')wei();
		if(b=='T')return 2;
		else return 4;
	}
	if(a=='T'){
		if(b=='B')return 5;
		else return type(b,a);
	}
	if(a=='B'){
		if(b=='T')return 5;
		else return type(b,a);
	}
}
char pos(int x){
	if(x>2*m+n)return 'R';
	if(x>2*m)return 'L';
	if(x>m)return 'B';
	return 'T';
}
int point(int x){
	if(pos(x)=='T')return x;
	if(pos(x)=='B')return x-m;
	if(pos(x)=='L')return x-m;
	return x-m-n;
}
inline int type(int a,int b){return type(pos(a),pos(b));}
int num[6];
void Read(){
	scanf("%d%d",&n,&m);
	if(n>m){swap(n,m);zhuan=1;}
	rep(i,1,n+m){
		int x,y;char a[2],b[2];
		scanf("%s%s%d%d",a+1,b+1,&x,&y);
		int u=getreal(a[1],x);int v=getreal(b[1],y);
		dui[u]=v;dui[v]=u;
	}
	rep(i,1,2*(n+m))num[type(i,dui[i])]++;
	rep(i,1,5)num[i]/=2;
	if(num[1]!=num[4])wei();
	if(num[2]!=num[3])wei();
	if(num[1]+num[3]!=n)wei();
	S=now=min(num[1],num[2]);
	if(num[1]<num[2]){
		jian=n-2*S;
	}
	else jian=2*S-n;
	rep(i,num[1]+1,m-num[2]){
		std_dui[i]=i+jian+m;
		std_dui[i+jian+m]=i;
	}
	
	rep(i,1,num[1]){
		std_dui[i]=i+2*m;std_dui[i+2*m]=i;
		std_dui[2*m-i+1]=2*m+2*n-i+1;std_dui[2*m+2*n-i+1]=2*m-i+1;
	}
	
	rep(i,1,num[2]){
		std_dui[m-i+1]=2*m+n+i;std_dui[2*m+n+i]=m-i+1;
		std_dui[2*m+n+1-i]=m+i;std_dui[m+i]=2*m+n+1-i;
	}
}
void KanMaoPian(){
	fail[0]=-1;int p;
	rep(i,1,N){
		for(p=fail[i-1];p!=-1&&line[p+1]!=line[i];p=fail[p]);
		fail[i]=p+1;
	}
}
int papapa(int me,bool jabby,int *A,int *B){
	int len=0;int y=me,z;
	bool jabby_is_god=1;
	while(jabby_is_god){
		if(jabby)z=std_dui[y];else z=dui[y];
		A[++len]=type(y,z);
		B[len]=point(y);
		if(!jabby)vis[z]=1;
		y=z;
		if(pos(y)=='T')y+=m;
		else if(pos(y)=='B')y-=m;
		else if(pos(y)=='L')y+=n;
		else y-=n;
		if(!jabby)vis[y]=1;
		if(y==me)break;
	}
	return len;
}
void dealwith(int s){
	if(s!=4&&s!=N)wei();
	if(s==4&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==3){
		if(!S)wei();//S--;
		ans[S]=b[1];
		ans[S+m]=b[2];
		ans[m-S+1]=b[3];
		ans[n-S+1+m]=b[4];
		S--;
		return ;
	}
	if(s==4&&a[1]==2&&a[2]==1&&a[3]==3&&a[4]==4){
		if(!S)wei();//S--;
		ans[m-S+1]=b[1];
		ans[m+S]=b[2];
		ans[S]=b[3];
		ans[n-S+1+m]=b[4];
		S--;
		return;
	}
	if(s^N)wei();
	rep(i,1,N)a[i+N]=a[i],b[i+N]=b[i];
	int p=0;
	rep(i,1,2*N){
		while(p!=-1&&a[i]!=line[p+1])p=fail[p];
		p++;
		if(p==N){
			papapa(++now,1,id,id);
			rep(j,i-N+1,i)ans[id[j-(i-N+1)+1]]=b[j];
			return;
		}
	}
	wei();
}
void Work(){
	N=papapa(now+1,1,line,id);
	KanMaoPian();
	rep(i,1,(n+m)*2)if(!vis[i]){
		int Len=papapa(i,0,a,b);
		dealwith(Len);
	}
}
void out(){
	if(S)wei();
	if(zhuan){
		rep(i,1,m)printf("%d ",ans[i]);
		printf("\n");
		rep(i,1,n)printf("%d ",ans[i+m]-m);
	}
	else{
		rep(i,1,n)printf("%d ",ans[i+m]-m);
		printf("\n");
		rep(i,1,m)printf("%d ",ans[i]);
	}
}
int main(){
	Read();
	Work();
	out();
}