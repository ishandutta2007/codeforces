#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
#include<string>
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 5005
int n,m;
bool op[N],val[N][1005]; //0:numb; 1: 2 vars(? or var)
char Bit[N][5]; //0 or; 1 xor; 2 and
string s[N],a[N],b[N];
int A[N],B[N]; //var's index
char tmp[1005];
bool ans1[1005],ans2[1005];
map<string,int> Map;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
void getvar() {
	memset(A,-1,sizeof(A));
	memset(B,-1,sizeof(B));
	rep(i,1,n) Map.insert(mp(s[i],i));
	rep(i,1,n) if (op[i]==1) {
		if (a[i][0]!='?') A[i]=Map[a[i]];
		if (b[i][0]!='?') B[i]=Map[b[i]];
	}
}
int calc(int x, int y, int p) {
	if (Bit[p][0]=='X') return x^y;
	if (Bit[p][0]=='O') return x|y;
	return x&y;
}
void getb(int p) {
	int x0=0,x1=0;
	rep(i,1,n) if (op[i]==1) {
		int tmp1,tmp2,tmp;
		if (a[i][0]=='?') tmp1=0; else tmp1=val[A[i]][p];
		if (b[i][0]=='?') tmp2=0; else tmp2=val[B[i]][p];
		tmp=calc(tmp1,tmp2,i); x0+=tmp; val[i][p]=tmp;
	}
	rep(i,1,n) if (op[i]==1) {
		int tmp1,tmp2,tmp;
		if (a[i][0]=='?') tmp1=1; else tmp1=val[A[i]][p];
		if (b[i][0]=='?') tmp2=1; else tmp2=val[B[i]][p];
		tmp=calc(tmp1,tmp2,i); x1+=tmp; val[i][p]=tmp;
	}
//	printf("%d %d %d\n",p,x0,x1); careful!!
	if (x0<=x1) ans1[p]=0; else ans1[p]=1;
	if (x0>=x1) ans2[p]=0; else ans2[p]=1;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(m);
	rep(i,1,n) {
		char S[20]; scanf("%s",S); s[i]=S;
		scanf("%s",S); scanf("%s",tmp);
		if (tmp[0]=='0'||tmp[0]=='1') {
			op[i]=0;
			rep(j,1,m) val[i][j]=tmp[j-1]-'0';
		}
		else {
			op[i]=1;
			a[i]=tmp; scanf("%s",Bit[i]);
			scanf("%s",tmp); b[i]=tmp;
		}
	}
	getvar();
//	printf("(%d %d)\n",A[3],B[3]);
	rep(i,1,m) getb(i);
	rep(i,1,m) printf("%d",ans1[i]); puts("");
	rep(i,1,m) printf("%d",ans2[i]); puts("");
	return 0;
}