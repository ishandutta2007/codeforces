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

const int N = 5e5+5;

int n;
int a[N];
int b[N];

bool cmp(int x,int y){return a[x]!=a[y]?a[x]>a[y]:x<y;}

bool bz[N];

struct point{
	int lst,nxt;
	int ad,siz,val;
}p[N*2];
int tot;

int newpoint(){
	tot++;
	p[tot].val=p[tot].siz=p[tot].ad=p[tot].lst=p[tot].nxt=0;
	return tot;
}

int he,ta;

void update(int x){
	if (!p[x].nxt||p[x].val>0)return;
	int y=p[x].nxt;
	p[x].nxt=p[y].nxt;
	p[x].siz+=p[y].siz;
	if(p[x].nxt)p[p[x].nxt].lst=x;
	p[x].val=p[y].val;
}

int s[N];

int check(int pv){
	a[n+1]=pv;
	s[0]=0;
	fo(i,1,n+1)b[i]=i,bz[i]=0,s[i]=0;
	fo(i,1,n+1)s[n-a[i]]++;
	fo(i,1,n+1)s[i]+=s[i-1];
	fo(i,1,n+1)b[s[n-a[i]]--]=i;
	//sort(b+1,b+n+2,cmp);
	tot=0;
	fo(i,1,n+1){
		int v=a[b[i]];
		if (i==1||a[b[i]]!=a[b[i-1]])p[newpoint()].val=v;
		p[tot].siz++;
	}
	if (!p[tot].val)tot--;
	fo(i,1,tot-1){
		p[i].nxt=i+1;
		p[i+1].lst=i;
		p[i].val-=p[i+1].val;
	}
	int start=a[b[1]];
	he=1,ta=tot;
	int x=1,now=p[1].siz,all=0;
	fo(i,1,n+1){
		bz[b[i]]=1;
		if (!start)continue;
		if (start>n+1-i)return bz[n+1]?2:0;
		int v=start;
		p[he].siz--;
		now--;
		if (!p[he].siz){
			start-=p[he].val;
			he=p[he].nxt;
			p[he].lst=0;
			if (!now)x=he,now=p[he].siz;
		}
		if(v>=p[he].siz)start--;
		for(;x&&now<v;){
			x=p[x].nxt;
			now=now+p[x].siz;
		}
		for(;x&&now-p[x].siz>=v;){
			now-=p[x].siz;
			x=p[x].lst;
		}
		if(now<v)return bz[n+1]?2:0;
		int d=v-(now-p[x].siz);
		if (d==p[x].siz){
			p[x].val--;
			now-=p[x].siz;
			update(x);
			now+=p[x].siz;
		}
		else{
			int y=newpoint();
			p[y].siz=d;
			p[x].siz-=d,now-=d;
			p[y].val=p[x].val-1;
			p[x].val=1;
			p[y].nxt=p[x].nxt;
			p[y].lst=x;
			p[x].nxt=y;
			if (p[y].nxt)p[p[y].nxt].lst=y;else ta=y;
			update(y);
			if (p[x].lst){
				int z=p[x].lst;
				p[z].val--;
				now-=p[x].siz+p[z].siz;
				update(z);
				now+=p[z].siz;
				x=z;
			}
		}
		if (!p[ta].val){
			if (x==ta){
				now-=p[ta].siz;
				x=p[ta].lst;
			}
			ta=p[ta].lst;
			p[ta].nxt=0;
		}
		continue;
		for(int x=ta,now=0;x;x=p[x].lst){
			now+=p[x].val;
			for(int tim=p[x].siz;tim;tim--)printf("%d ",now);
		}
		putchar('\n');
	}
	return 1;
}

int main(){
//	freopen("data.in","r",stdin);
	n=get();
	LL sum=0;
	fo(i,1,n)a[i]=get();
	fo(i,1,n)sum+=a[i];
	//check(1);return 0;
	int d=sum&1;
	int l=0,r=n/2,lw=1e9,rw=-1e9;
	while(l<=r){
		int mid=(l+r)/2;
		int ret=check(mid*2+d);
		if (ret==0)l=mid+1;
		else lw=mid,r=mid-1;
	}
	l=0,r=n/2;
	while(l<=r){
		int mid=(l+r)/2;
		int ret=check(mid*2+d);
		if (ret==2)r=mid-1;
		else rw=mid,l=mid+1;
	}
	if(lw<=rw)fo(i,lw,rw)printf("%d%c",i*2+d,i==rw?'\n':' ');
	else printf("-1\n");
	return 0;
}