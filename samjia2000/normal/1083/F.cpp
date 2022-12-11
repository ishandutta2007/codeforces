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

const int N = 2e5+5;
const int B = 500;
const int L = (1<<14)+5;

int n,q;
int a[N],b[N],c[N],d[N];
int k;
int cnt[B][L];
int blk;
int st[N],ed[N],len;
int que[N],pos[N],be[N],u;
int all[N],val[N];
int sum[N];
int ans,wr;
int lef[N],rig[N];

void change(int x,int v){
	d[x]^=v;
	int w=pos[x];
	int res=x%k;
	if (all[res])wr--;else ans-=val[res];
	if (be[w]){
		int p=be[w];
		sum[p]=0;
		fo(i,lef[p],rig[p]){
			sum[p]^=d[que[i]];
			if (i>=w)cnt[p][sum[p]^v]--;else cnt[p][sum[p]]--;
			cnt[p][sum[p]]++;
		}
	}
	all[res]=val[res]=0;
	int L=st[res];
	for(;L+blk-1<=ed[res];L+=blk){
		int R=L+blk-1;
		int p=be[L];
		val[res]+=cnt[p][all[res]];
		all[res]^=sum[p];
	}
	for(;L<=ed[res];L++){
		all[res]^=d[que[L]];
		if (!all[res])val[res]++;
	}
	if (all[res])wr++;else ans=ans+val[res];
}

int main(){
	n=get();k=get();q=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)b[i]=get();
	fo(i,1,n)c[i]=a[i]^b[i];
	fo(i,1,n+1)d[i]=c[i]^c[i-1];
	blk=sqrt(n);
	fo(res,0,k-1){
		st[res]=len+1;
		for(int i=res==0?k:res;i<=n+1;i+=k)que[++len]=i;
		ed[res]=len;
	}
	fo(i,1,n+1)pos[que[i]]=i;
	ans=0,wr=0;
	fo(res,0,k-1){
		for(int L=st[res];L+blk-1<=ed[res];L+=blk){
			int R=L+blk-1;
			lef[++u]=L;rig[u]=R;
			fo(i,L,R){
				be[i]=u;
				sum[u]^=d[que[i]];
				cnt[u][sum[u]]++;
			}
		}
		fo(i,st[res],ed[res]){
			all[res]^=d[que[i]];
			if (!all[res])val[res]++;
		}
		if (all[res])wr++;else ans=ans+val[res];
	}
	if (wr)printf("-1\n");else printf("%d\n",n+1-ans);
	fo(_,1,q){
		char s[10];
		scanf("%s",s);
		int x=get(),v=get();
		if (s[0]=='a'){v^=a[x];a[x]^=v;}
		else{v^=b[x];b[x]^=v;}
		c[x]^=v;
		change(x,v);
		change(x+1,v);
		if (wr)printf("-1\n");
		else printf("%d\n",n+1-ans);
	}
	return 0;
}