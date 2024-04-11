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

const int N = 305;

struct point{
	LL x,y;
	point(const LL x_=0,const LL y_=0){x=x_;y=y_;}
	friend point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
	friend point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
	friend LL operator *(point a,point b){return a.x*b.y-a.y*b.x;}
	friend LL operator ^(point a,point b){return a.x*b.x+a.y*b.y;}
	friend LL distance(point a,point b){return (a-b)^(a-b);}
}a[N];

int n;

LL cross(point a,point b,point c){return (b-a)*(c-a);}

int num1[N],num2[N];
int k1,k2;
LL val[N];
int num[N],k;
point O;

bool cmp(int x,int y){return (a[x]-O)*(a[y]-O)>0;}

int rk1[N],rk2[N];
int bit[N];
LL cnt[N];

void add(int n,int x){
	x=n-x+1;
	for(;x<=n;x+=x&-x)bit[x]++;
}

int query(int n,int x){
	x=n-x+1;
	int ret=0;
	for(;x;x-=x&-x)ret+=bit[x];
	return ret;
}

int pos[N][N];
int t[N][N];

bool cmp1(int x,int y){
	point ax=a[x]-O,ay=a[y]-O;
	int tx=ax.y==0?(ax.x>0?1:2):(ax.y>0?1:2);
	int ty=ay.y==0?(ay.x>0?1:2):(ay.y>0?1:2);
	if (tx!=ty)return tx<ty;
	return ax*ay>=0;
}

int main(){
	n=get();
	fo(i,1,n){
		a[i].x=get();a[i].y=get();
	}
	LL ans=0;
	fo(i,1,n){
		int l=0;
		fo(j,1,n)
		if (i!=j)t[i][++l]=j;
		O=a[i];
		sort(t[i]+1,t[i]+1+l,cmp1);
		fo(j,1,l)pos[i][t[i][j]]=j;
	}
	fo(sx,1,n)
		fo(sy,1,n)
		if (sx!=sy){
			k=k1=k2=0;
			/*fo(i,1,n)
			if (i!=sx&&i!=sy){
				val[i]=cnt[i]=0;
				if ((a[i]-a[sx])*(a[sy]-a[sx])>0)num2[++k2]=num1[++k1]=i;
				else num[++k]=i;
			}
			O=a[sx];
			sort(num1+1,num1+1+k1,cmp);
			O=a[sy];
			sort(num2+1,num2+1+k2,cmp);
			reverse(num2+1,num2+1+k2);*/
			fo(i,1,n)val[i]=cnt[i]=0;
			{
				int p=pos[sx][sy]%(n-1)+1;
				for(;p!=pos[sx][sy]&&cross(a[sx],a[sy],a[t[sx][p]])>=0;p=p%(n-1)+1)num[++k]=t[sx][p];
				for(;p!=pos[sx][sy]&&cross(a[sx],a[sy],a[t[sx][p]])<=0;p=p%(n-1)+1)num1[++k1]=t[sx][p];
			}
			{
				int p=(pos[sy][sx])%(n-1)+1;
				for(;p!=pos[sy][sx]&&cross(a[sy],a[sx],a[t[sy][p]])>=0;p=p%(n-1)+1)num2[++k2]=t[sy][p];
				reverse(num2+1,num2+1+k2);
			}
			fo(i,1,k1)rk1[num1[i]]=i;
			fo(i,1,k2)rk2[num2[i]]=i,bit[i]=0;
			LL sum=0;
			fd(i,k1,1){
				int x=num1[i];
				val[x]=query(k1,rk2[x]);
				add(k1,rk2[x]);
				sum+=val[x];
			}
		/*	O=a[sx];
			sort(num+1,num+1+k,cmp);*/
			int w=1;
			LL pre=0;
			fo(i,1,k){
				for(;w<=k1&&cross(a[sx],a[num[i]],a[num1[w]])>=0;w++)
					pre+=val[num1[w]];
				val[num[i]]+=pre;
				cnt[num[i]]+=w-1;
			}
		/*	O=a[sy];
			sort(num+1,num+1+k,cmp);
			reverse(num+1,num+1+k);*/
			{
				k=0;
				int p=(pos[sy][sx]+n-3)%(n-1)+1;
				for(;p!=pos[sy][sx]&&cross(a[sy],a[sx],a[t[sy][p]])<=0;p=(p+n-3)%(n-1)+1)num[++k]=t[sy][p];
			}
			w=1,pre=0;
			fo(i,1,k){
				for(;w<=k2&&cross(a[sy],a[num[i]],a[num2[w]])<=0;w++)
					pre+=val[num2[w]];
				val[num[i]]+=pre;
				cnt[num[i]]+=w-1;
			}
			fo(i,1,k){
				int x=num[i];
				LL v=(k1-cnt[x])*(k1-cnt[x]-1)/2-(sum-val[x]);
				ans=ans+v;
			}
		}
	ans=ans/5;
	cout<<ans<<endl;
	return 0;
}