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

const int N = 3e5+5;

int n,m;
int a[N];
pair<int,int> ans[N*5];
bool vis[N];
int k,que[N];
int per[N];

void Swap(int x,int y){
	swap(per[x],per[y]);
	if (2*abs(x-y)<n)fprintf(stderr,"Wrong %d %d\n",x,y);
	ans[++m]=make_pair(x,y);
}

void solve(int x,int y){
	if (x>y)swap(x,y);
	if (2*abs(x-y)>=n){
		Swap(x,y);
		return;
	}
	if (y<=n/2){
		Swap(x,n);
		Swap(y,n);
		Swap(x,n);
		return;
	}
	if (x>n/2){
		Swap(1,x);
		Swap(1,y);
		Swap(1,x);
		return;
	}
	Swap(x,n);
	Swap(1,y);
	Swap(1,n);
	Swap(1,y);
	Swap(x,n);
}

int main(){
	n=get();
	fo(i,1,n)per[i]=a[i]=get();
	fo(i,1,n)
	if (!vis[i]){
		k=0;
		for(int x=i;!vis[x];x=a[x])vis[que[++k]=x]=1;
		fo(w,1,k-1)
		solve(que[1],que[w+1]);
	}
	bool yes=1;
	fo(i,1,n)yes&=(per[i]==i);
	if (!yes)fprintf(stderr,"Wrong\n");
	printf("%d\n",m);
	fo(i,1,m)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}