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

const int N = 1.1e5+5;
const int L = 55;

int n,W,q;
int a[N];
int qry[N];
int K[N];
int rmq0[N][19],rmq1[N][19];
int lg[N];
int Len[N][L];
int B;
int ad[N];

int getmax(int l,int r){
	int t=lg[r-l+1];
	return max(rmq1[l][t],rmq1[r-(1<<t)+1][t]);
}

int getmin(int l,int r){
	int t=lg[r-l+1];
	return min(rmq0[l][t],rmq0[r-(1<<t)+1][t]);
}

int to[N],tot[N],w[N];

bool cmp(int x,int y){return K[x]>K[y];}

struct variation{
	int x,v;
	variation(const int x_=0,const int v_=0){x=x_;v=v_;}
	friend bool operator <(variation a,variation b){
		return a.v!=b.v?a.v>b.v:a.x>b.x;
	}
}var[N*53];
int m;
int vis[N],tim;
int lim;
int key[N],u;
int pos[N];
int vt[N];
int ans[N];

void push(int x){
	w[x]++;
	vis[x]=++tim;
	if (w[x]==B){
		ad[x]=B;
		to[x]=tot[x]=0;
		key[u=1]=x;
	}
	else{
		key[u=1]=x;
		int len=0;
		for(int now=x;len<B&&now<=n&&w[now]!=B;){
			len+=w[now];
			key[++u]=now=now+w[now];
		}
		to[x]=key[u];
		tot[x]=u-1;
	}
	int Lef=max(1,x-B+1);
	int t=u;
	vt[x]=0;
	fd(i,x-1,Lef){
		if (w[i]!=B&&vis[i+w[i]]==tim){
			vis[i]=tim;
			vt[i]=vt[i+w[i]]+1;
		}
	}
	fd(i,x-1,Lef)
	if(vis[i]==tim){
		while(t>1&&key[t-1]-i>=B)t--;
		to[i]=key[t];
		tot[i]=vt[i]+t-1;
	}
}

int query(int k){
	int ret=0;
	for(int x=1;x<=n;){
		if (w[x]<B){
			ret+=tot[x];
			x=to[x];
		}
		else{
			ret++;
			while(ad[x]<lim&&getmin(x,x+ad[x])+W-getmax(x,x+ad[x])>=k)ad[x]++;
			if (ad[x]>=lim){
				int l=x,r=n,y=x;
				while(l<=r){
					int mid=(l+r)/2;
					if (getmin(x,mid)+W-getmax(x,mid)>=k)y=mid,l=mid+1;
					else r=mid-1;
				}
				x=y+1;
			}
			else x+=ad[x];
		}
	}
	return ret;
}

int main(){
	n=get();W=get();q=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n)rmq0[i][0]=rmq1[i][0]=a[i];
	fo(j,1,log(n)/log(2))
		fo(i,1,n-(1<<j)+1){
			rmq0[i][j]=min(rmq0[i][j-1],rmq0[i+(1<<(j-1))][j-1]);
			rmq1[i][j]=max(rmq1[i][j-1],rmq1[i+(1<<(j-1))][j-1]);
		}
	fo(i,1,n)lg[i]=log(i)/log(2);
	fo(i,1,q)K[qry[i]=i]=get();
	sort(qry+1,qry+1+q,cmp);
	B=exp(log(n)/3)+1;
	if (B==1)B=2;
	lim=B*B;
	fo(i,1,n){
		int mx=a[i],mi=a[i];
		int len=min(B,n-i+1);
		fo(j,1,len){
			mx=max(mx,a[i+j-1]);
			mi=min(mi,a[i+j-1]);
			Len[i][j]=mi+W-mx;
		}
		w[i]=1;
		fo(j,2,len)var[++m]=variation(i,Len[i][j]);
		ad[i]=B;
	}
	fd(i,n,1){
		to[i]=min(n+1,i+B);
		tot[i]=to[i]-i;
	}
	sort(var+1,var+1+m);
	int p=1;
	fo(i,1,q){
		int id=qry[i];
		int k=K[id];
		for(;p<=m&&var[p].v>=k;p++)push(var[p].x);
		ans[id]=query(k)-1;
	}
	fo(i,1,q)printf("%d\n",ans[i]);
	return 0;
}