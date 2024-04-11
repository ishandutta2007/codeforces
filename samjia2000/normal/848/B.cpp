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

const int N = 100010;

struct dancer{
	int p,t,id;
}a[N],b[N],lef[N],rig[N];
int n;
int kx,ky;
int w,h;
struct point{
	int x,y;
	point(const int x_=0,const int y_=0){x=x_;y=y_;}
}ans[N];

bool cmp(dancer a,dancer b){
	if (a.t-a.p!=b.t-b.p)return a.t-a.p<b.t-b.p;
	return a.t<b.t;
}

int main(){
	n=get();w=get();h=get();
	fo(i,1,n){
		int g=get(),p=get(),t=get();
		if (g==1){
			a[++kx].p=p;
			a[kx].t=t;
			a[kx].id=i;
		}
		else{
			b[++ky].p=p;
			b[ky].t=t;
			b[ky].id=i;
		}
	}
	sort(a+1,a+1+kx,cmp);
	sort(b+1,b+1+ky,cmp);
	int wx=1,wy=1;
	while(wx<=kx||wy<=ky){
		int val;
		if (wx<=kx&&wy<=ky)val=min(a[wx].t-a[wx].p,b[wy].t-b[wy].p);
		else val=wx<=kx?a[wx].t-a[wx].p:b[wy].t-b[wy].p;
		int kl=0,kr=0;
		while(wx<=kx&&a[wx].t-a[wx].p==val)rig[++kr]=a[wx++];
		while(wy<=ky&&b[wy].t-b[wy].p==val)lef[++kl]=b[wy++];
		fo(i,1,kl/2)swap(lef[i],lef[kl-i+1]);
		if (kl<kr){
			fo(i,1,kl)ans[lef[i].id]=point(rig[i].p,h);
			fo(i,1,kr-kl)ans[rig[i].id]=point(rig[i+kl].p,h);
			fo(i,kr-kl+1,kr)ans[rig[i].id]=point(w,lef[i-(kr-kl)].p);
		}
		else{
			fo(i,1,kr)ans[rig[i].id]=point(w,lef[kl-kr+i].p);
			fo(i,1,kr)ans[lef[i].id]=point(rig[i].p,h);
			fo(i,kr+1,kl)ans[lef[i].id]=point(w,lef[i-kr].p);
		}
	}
	fo(i,1,n)printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}