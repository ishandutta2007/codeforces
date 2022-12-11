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

const int N = 200005;

int tree[N*32][2];
int tot;
int n,a[N];
LL ans;

void add(int &now,int v,int w){
	if (!now)now=++tot;
	if (w==-1)return;
	if ((v&(1<<w))>0)add(tree[now][1],v,w-1);
	else add(tree[now][0],v,w-1);
}

int getv(int now,int v,int w){
	if (w==-1)return 0;
	int fx=((v&(1<<w))>0);
	if(tree[now][fx])return getv(tree[now][fx],v,w-1);
	return getv(tree[now][fx^1],v,w-1)+(1<<w);
}

void solve(int l,int r,int L,int R){
	if (L>R)return;
	if (l==r)return;
	int mid=(l+r)/2;
	int w=R+1;
	fo(i,L,R)
	if (a[i]>mid){w=i;break;}
	if (L<w&&w<=R){
		int rt=tot=1;
		fo(i,L,w-1)add(rt,a[i],29);
		int mv=2e+9;
		fo(i,w,R)mv=min(mv,getv(rt,a[i],29));
		ans=ans+mv;
		fo(i,1,tot)tree[i][0]=tree[i][1]=0;
	}
	solve(l,mid,L,w-1);
	solve(mid+1,r,w,R);
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	sort(a+1,a+1+n);
	solve(0,(1<<30)-1,1,n);
	printf("%I64d\n",ans);
	return 0;
}