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

const int N = 2e3+5;
const int mo = 998244353;

int n;
int a[N][N];
LL f[N][N];

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
		if (tim&1)ret=ret*x%mo;
	return ret;
}

int tree[2][N];

void add(int t,int x,int v){for(;x<=n;x+=x&-x)tree[t][x]+=v;}

int query(int t,int x){int ret=0;for(;x;x-=x&-x)ret+=tree[t][x];return ret;}

bool bz0[N],bz1[N];

int main(){
	n=get();
	fo(i,1,n)fo(j,1,n)a[i][j]=get();
	f[0][0]=1;
	fo(i,1,n){
		f[i][0]=f[i-1][0]*i%mo;
		fo(j,1,i)f[i][j]=dec(f[i][j-1],f[i-1][j-1]);
	}
	LL ans=0;
	fo(i,1,n){
		fo(x,0,n)bz0[x]=bz1[x]=tree[0][x]=tree[1][x]=0;
		int res=n;
		LL r=0;
		if (i==1){
			fo(j,1,n){
				int x=a[i][j];
				add(0,x,1);
				r=(r+f[n-j][0]*(x-query(0,x)))%mo;
			}
		}
		else{
			fo(x,1,n)add(0,x,1),add(1,x,1);
			fo(j,1,n){
				int x=a[i][j];
				int y=a[i-1][j];
				int v0=query(0,x-1),v1=query(1,x-1);
				if (x>y&&!bz0[y])v0--,v1--;
				int r1=!bz0[y]?res-1:res;
				r=(r+f[n-j][r1]*(v0-v1)%mo+(r1?f[n-j][r1-1]*v1%mo:0))%mo;
				add(0,x,-1);
				if (!bz1[x])add(1,x,-1),res--;
				if (!bz0[y])add(1,y,-1),res--;
				bz0[x]=bz1[y]=1;
			}
		}
		ans=(ans+r*quickmi(f[n][n],n-i))%mo;
	}
	cout<<ans<<endl;
	return 0;
}