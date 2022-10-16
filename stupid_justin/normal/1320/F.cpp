
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=2e5+5;
const int M=1e5+5;
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,m,k,t;
int id(int x,int y,int z){return (x-1)*m*k+(y-1)*k+z;}
int a[N];
vector<int> D[N];
int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
bool chk(int x,int y,int z){return 1<=x && x<=n && 1<=y && y<=m && 1<=z && z<=k;}
void ins(int,int,int,int,int);
void del(int,int,int);
void ins(int x,int y,int z,int d,int t)
{
	int i=id(x,y,z);
    if (!chk(x,y,z) && t) {puts("-1");exit(0);}
    if (!chk(x,y,z)) return;
	if (!t) {if (a[i]>0) del(x,y,z);a[i]=0;ins(x+dx[d],y+dy[d],z+dz[d],d,t);}
	else if (a[i]==-1 || a[i]==t) a[i]=t,D[i].push_back(d);
	else if (!a[i]) ins(x+dx[d],y+dy[d],z+dz[d],d,t);
	else del(x,y,z),a[i]=0,ins(x+dx[d],y+dy[d],z+dz[d],d,t);
}
void del(int x,int y,int z)
{
	int i=id(x,y,z);
	while(!D[i].empty()){int d=D[i].back();D[i].pop_back();ins(x+dx[d],y+dy[d],z+dz[d],d,a[i]);}
}
signed main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    rd(n);rd(m);rd(k);memset(a,-1,sizeof(a));
    for (int i=1;i<=m;i++) for (int j=1;j<=k;j++) rd(t),ins(1,i,j,0,t);
    for (int i=1;i<=m;i++) for (int j=1;j<=k;j++) rd(t),ins(n,i,j,1,t);
    for (int i=1;i<=n;i++) for (int j=1;j<=k;j++) rd(t),ins(i,1,j,2,t);
    for (int i=1;i<=n;i++) for (int j=1;j<=k;j++) rd(t),ins(i,m,j,3,t);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) rd(t),ins(i,j,1,4,t);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) rd(t),ins(i,j,k,5,t);
    for (int i=1;i<=n*m*k;i++) if (a[i]==-1) cout<<"1 ";else cout<<a[i]<<" ";cout<<endl;
}


/*
4 3 2

1 4
3 2
6 5

1 4
3 2
6 7

1 4
1 4
0 0
0 7

6 5
6 5
0 0
0 7

1 3 6
1 3 6
0 0 0
0 0 7

4 3 5
4 2 5
0 0 0
0 0 7
*/