//by samjia2000
#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

int getrand(){
	int s=0;
	fo(i,1,3)s=s*1000+rand()%1000;
	return s;
}

const int N = 1e3+5;

int n;
LL L,B;
int num[N];
LL pos[N];
pair<LL,LL>ans[N];
LL P;
int be[N];

int QUERY;

int a[1005][50005];

const int E=50000;

void init(){
	srand(74815215);
	fo(i,1,n){
		fo(j,1,L){
			int x=getrand()%E+1;
			for(;a[i][x];)x=getrand()%E+1;
			a[i][x]=1;
		}
		fo(j,1,E)a[i][j]+=a[i][j-1];
		//if (i>1)fo(j,1,E)a[i][j]=a[i-1][j];
//		fo(j,1,E)if (a[i][j]>a[i][j-1])fprintf(stderr,"%d ",j);;fprintf(stderr,"\n");
	}
}

LL query(int x,LL w){
	QUERY++;
	printf("? %d %I64d\n",x,w);
	fflush(stdout);
	LL ret;
	scanf("%I64d",&ret);
	return ret;
	//fprintf(stderr,"? %d %I64d\n",x,w);
	if (w>E){
		//fprintf(stderr,"%d\n",L);
		return L;
	}
	//fprintf(stderr,"%d\n",a[x][w]);
	return a[x][w];
	
}

LL getpos(int x,LL v,LL l=0,LL r=1e18){
	LL w=r;
	for(;l<=r;){
		LL mid=(l+r)/2;
		if (query(x,mid)>=v)w=mid,r=mid-1;
		else l=mid+1;
	}
	return w;
}

bool cmp(int x,int y){return be[x]<be[y];}

LL SORT(int l,int r,int k,LL LEFT,LL RIGHT){
	if (l==r)return getpos(num[l],P);
	int x=num[rand()%(r-l+1)+l];
	LL w=getpos(x,P,LEFT,RIGHT);
	int cntl=0,cntr=0,M=0;
	fo(i,l,r){
		LL tmp=query(num[i],w);
		if (tmp>P)be[num[i]]=1,cntl++;
		else
			if (tmp==P)be[num[i]]=2,M++;
			else be[num[i]]=3,cntr++;
	}
	sort(num+l,num+r+1,cmp);
	if (k<=cntl)return SORT(l,l+cntl-1,k,LEFT,w);
	if (k>cntl+M)return SORT(r-cntr+1,r,k-cntl-M,w,RIGHT);
	return w;
}

void solve(int l1,int r1,int l2,int r2,LL LEFT,LL RIGHT){
	if (l1==r1){
		pos[num[l2]]=RIGHT;
		//getpos(num[l2],B*l1,LEFT,RIGHT);
		return;
	}
	int mid=(l1+r1)/2;
	P=B*mid;
	int len=r2-l2+1;
	int w=mid-l1+1;
	LL D=SORT(l2,r2,w,LEFT,RIGHT);
	solve(l1,mid,l2,l2+w-1,LEFT,D);
	solve(mid+1,r1,l2+w,r2,D,RIGHT);
}

int main(){
	cin>>n>>L;
	//init();
	fo(i,1,n)num[i]=i;
	B=L/n;
	solve(1,n,1,n,0ll,LL(1e18));
	LL lst=0;
	fo(i,1,n){
		int x=num[i];
		ans[x]=make_pair(lst,pos[x]);
		lst=pos[x];
	}
	fprintf(stderr,"CALLS OF QUERY : %d\n",QUERY);
	printf("!\n");
	fflush(stdout);
	fo(i,1,n){
		printf("%lld %lld\n",ans[i].first,ans[i].second);
		fflush(stdout);
	}
	return 0;
}