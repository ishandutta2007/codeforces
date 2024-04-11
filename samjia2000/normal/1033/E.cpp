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

const int N = 605;

int n;
int dep[N];
struct Query{
	int len;
	int a[N];
	
	int &operator [](int x){return a[x];}
	
	bool bz[N];
	
	int query(){
		if (!len)return 0;
		fo(i,1,n)bz[i]=0;
		fo(i,1,len)bz[a[i]]=1;
		len=0;
		fo(i,1,n)if (bz[i])a[++len]=i;
		printf("? %d\n",len);
		fo(i,1,len)printf("%d ",a[i]);
		putchar('\n');
		fflush(stdout);
		return get();
	}
}qry;
bool odd;
int key[N],k;
int que[N],u;
int pt[N],m;
int pre;

void getpt(int l,int r){
	qry.len=u+r-l+1;
	fo(i,1,u)qry[i]=que[i];
	fo(i,l,r)qry[i-l+1+u]=key[i];
	int res=qry.query()-pre;
	qry.len=r-l+1;
	fo(i,l,r)qry[i-l+1]=key[i];
	res-=qry.query();
	if (!res)return;
	if (l==r){
		pt[++m]=key[l];
		return;
	}
	int mid=(l+r)/2;
	getpt(l,mid);
	getpt(mid+1,r);
}

int st[N],ed[N];
int line1[N],line2[N];

pair<int,int> getcir(int l,int r){
	qry.len=r-l+1;
	fo(i,l,r)qry[i-l+1]=pt[i];
	int tmp=qry.query();
	if (!tmp)return make_pair(0,0);
	int mid=(l+r)/2;
	pair<int,int>ret=getcir(l,mid);
	if (ret.first)return ret;
	ret=getcir(mid+1,r);
	if (ret.first)return ret;
	int L=1,R=mid;
	while(L<=R){
		int Mid=(L+R)/2;
		qry.len=Mid-L+1+r-mid;
		int w=1;
		fo(i,L,Mid)qry[w++]=pt[i];
		fo(i,mid+1,r)qry[w++]=pt[i];
		if (qry.query())ret.first=Mid,R=Mid-1;
		else L=Mid+1;
	}
	L=mid+1,R=r;
	while(L<=R){
		int Mid=(L+R)/2;
		qry.len=Mid-L+1+1;
		int w=1;
		fo(i,L,Mid)qry[w++]=pt[i];
		qry[w++]=pt[ret.first];
		if (qry.query())ret.second=Mid,R=Mid-1;
		else L=Mid+1;
	}
	return ret;
}

void getline(int x,int d,int *line){
	int lst=x;
	int w;
	line[w=1]=x;
	fd(D,d-1,1){
		int l=st[D],r=ed[D];
		int key=0;
		while(l<=r){
			int mid=(l+r)/2;
			qry.len=mid-l+1+1;
			int w=1;
			fo(i,l,mid)qry[w++]=que[i];
			qry[w++]=lst;
			if (qry.query())r=mid-1,key=mid;
			else l=mid+1;
		}
		line[++w]=lst=que[key];
	}
}

void bfs(int St){
	dep[St]=1;
	k=0;
	fo(i,1,n)if (!dep[i])key[++k]=i;
	que[u=1]=St;
	pre=0;
	int d=1;
	st[1]=ed[1]=1;
	while(1){
		d++;
		qry.len=u+k;
		fo(i,1,u)qry[i]=que[i];
		fo(i,1,k)qry[u+i]=key[i];
		int all=qry.query()-pre;
		qry.len=k;
		fo(i,1,k)qry[i]=key[i];
		all-=qry.query();
		if (all){
			m=0;
			getpt(1,k);
			fo(i,1,m)dep[pt[i]]=d;
			int k_=0;
			fo(i,1,k)if (!dep[key[i]])key[++k_]=key[i];
			k=k_;
			pre+=all;
			pair<int,int>s=getcir(1,m);
			if (s.first){
				int x=pt[s.first],y=pt[s.second];
				getline(x,d,line1);
				getline(y,d,line2);
				odd=1;
				printf("N %d\n",d*2-1);
				fo(i,1,d)printf("%d ",line1[i]);
				fd(i,d-1,1)printf("%d ",line2[i]);
				putchar('\n');
				fflush(stdout);
				return;
			}
			st[d]=u+1;
			ed[d]=u+m;
			fo(i,1,m)que[++u]=pt[i];
		}
		else break;
	}
}

int main(){
	n=get();
	odd=0;
	fo(i,1,n)
	if (!dep[i]){
		bfs(i);
		if (odd)return 0;
	}
	int cnt=0;
	fo(i,1,n)if (dep[i]&1)cnt++;
	printf("Y %d\n",cnt);
	fo(i,1,n)if (dep[i]&1)printf("%d ",i);
	putchar('\n');
	fflush(stdout);
	return 0;
}