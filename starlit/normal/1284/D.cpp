#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,m,tb[N*4],t,tp,al,
la[N],ra[N],lb[N],rb[N],
b1[N*4],b2[N*4];
struct dat{
	int x,l,r;bool typ;
}a[N*2];
inline void rd(int&x){
	scanf("%d",&x),tb[t++]=x;
}
inline void find(int&x){
	x=upper_bound(tb,tb+t,x)-tb;
}
bool cmp(dat a,dat b){
	return a.x<b.x;
}
inline void ins1(int x){
	for(;x<=t;x+=x&-x)b1[x]++;
}
inline void ins2(int x){
	for(;x;x-=x&-x)b2[x]++;
}
inline int qry1(int x){
	int y=0;
	for(;x;x-=x&-x)y+=b1[x];
	return y;
}
inline int qry2(int x){
	int y=0;
	for(;x<=t;x+=x&-x)y+=b2[x];
	return y;
}
inline void sol(int*La,int*Ra,int*Lb,int*Rb){
	m=al=0;
	for(int i=1;i<=t;i++)b1[i]=b2[i]=0;
	for(int i=0;i<n;i++)
	a[m++]={La[i],Lb[i],Rb[i],0},
	a[m++]={Ra[i],Lb[i],Rb[i],1};
	sort(a,a+m,cmp);
	for(int i=0,j;i<m;i=j){
		for(j=i;j<m&&a[j].x==a[i].x;j++)
		if(!a[j].typ){
			//cerr<<"chk ["<<a[j].l<<','<<a[j].r<<"]\n";
			tp=qry1(a[j].l-1)+qry2(a[j].r+1);
			//cerr<<tp<<"&"<<al<<endl;
			if(tp!=al){puts("NO");exit(0);}
		}
		for(j=i;j<m&&a[j].x==a[i].x;j++)
		if(a[j].typ){
			//cerr<<"ins ["<<a[j].l<<','<<a[j].r<<"]\n";
			al++,ins1(a[j].r),ins2(a[j].l);
		}
	}
	al=0;
	for(int i=1;i<=t;i++)b1[i]=b2[i]=0;
	for(int i=m-1,j;~i;i=j){
		for(j=i;j>=0&&a[j].x==a[i].x;j--)
		if(a[j].typ){
			//cerr<<"chk ["<<a[j].l<<','<<a[j].r<<"]\n";
			tp=qry1(a[j].l-1)+qry2(a[j].r+1);
			if(tp!=al){puts("NO");exit(0);}
		}
		for(j=i;j>=0&&a[j].x==a[i].x;j--)
		if(!a[j].typ){
			//cerr<<"ins ["<<a[j].l<<','<<a[j].r<<"]\n";
			al++,ins1(a[j].r),ins2(a[j].l);
		}
	}
}
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	rd(la[i]),rd(ra[i]),rd(lb[i]),rd(rb[i]);
	sort(tb,tb+t);t=unique(tb,tb+t)-tb;
	//cerr<<"???\n";
	for(int i=0;i<n;i++)
	find(la[i]),find(ra[i]),find(lb[i]),find(rb[i]);
	sol(la,ra,lb,rb),sol(lb,rb,la,ra);
	puts("YES");
}