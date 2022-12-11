#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

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

const int mo = 998244353;
const int N = 1e5+5;
const int B = 500;
const int INF = 1e9;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int n,k;
int a[N];
LL f[N];
int blk;
int ad[N];
struct position{
	int v;
	LL sum;
	position(const int v_=0,const LL sum_=0){sum=sum_;v=v_;}
}b[B][B];
int pos[B],siz[B];
int val[N];
LL sum[B];
pair<int,int>lst[N];
int vis[N],tim,cnt0[N],cnt1[N];
LL s0[N],s1[N];
position b0[B],b1[B];

void add(int be,int l,int r,int v){
	int L=(be-1)*blk+1,R=min(n,be*blk);
	tim++;
	fo(i,L,R){
		val[i]+=ad[be];
		if(vis[val[i]]<tim)vis[val[i]]=tim,cnt0[val[i]]=cnt1[val[i]]=s0[val[i]]=s1[val[i]]=0;
		if (i>=l&&i<=r){
			cnt0[val[i]]++,s0[val[i]]=add(s0[val[i]],f[i-1]);
			val[i]+=v;
		}
		else cnt1[val[i]]++,s1[val[i]]=add(s1[val[i]],f[i-1]);
	}
	int k0=0,k1=0;
	fo(i,1,siz[be]){
		b[be][i].v+=ad[be];
		if (cnt0[b[be][i].v])b0[++k0]=position(b[be][i].v+v,s0[b[be][i].v]);
		if (cnt1[b[be][i].v])b1[++k1]=position(b[be][i].v,s1[b[be][i].v]);
	}
	ad[be]=0;
	int h0=1,h1=1;
	siz[be]=0;
	for(;h0<=k0&&h1<=k1;){
		if (b0[h0].v==b1[h1].v){
			b[be][++siz[be]]=position(b0[h0].v,add(b0[h0].sum,b1[h1].sum));
			h0++,h1++;
		}
		else{
			if (b0[h0].v<b1[h1].v)b[be][++siz[be]]=b0[h0++];
			else b[be][++siz[be]]=b1[h1++];
		}
	}
	for(;h0<=k0;)b[be][++siz[be]]=b0[h0++];
	for(;h1<=k1;)b[be][++siz[be]]=b1[h1++];
	pos[be]=0;
	sum[be]=0;
	for(;pos[be]<siz[be]&&b[be][pos[be]+1].v<=k;)sum[be]+=b[be][++pos[be]].sum;
	sum[be]=sum[be]%mo;
}

void add(int l,int r,int v){
	if (l>r)return;
	int bel=(l-1)/blk+1,ber=(r-1)/blk+1;
	if(bel==ber){
		add(bel,l,r,v);
		return;
	}
	add(bel,l,min(n,bel*blk),v);
	add(ber,(ber-1)*blk+1,r,v);
	for(int w=bel+1;w<ber;w++){
		ad[w]+=v;
		for(;b[w][pos[w]].v+ad[w]>k;)sum[w]-=b[w][pos[w]--].sum;
		for(;pos[w]<siz[w]&&b[w][pos[w]+1].v+ad[w]<=k;)sum[w]+=b[w][++pos[w]].sum;
		sum[w]=(sum[w]%mo+mo)%mo;
	}
}

int main(){
	n=get();k=get();
	fo(i,1,n)a[i]=get();
	f[0]=1;
	blk=sqrt(n)+1;
	for(int w=1,x=1;x<=n;x+=blk,w++){
		pos[w]=siz[w]=1;
		int R=min(n,x+blk-1);
		b[w][1]=position(0,0);
		b[w][0]=position(-INF,0);
		b[w][2]=position(INF,0);
		sum[w]=0;
	}
	fo(i,1,n){
		int be=(i-1)/blk+1;
		sum[be]=add(sum[be],f[i-1]);
		fo(j,1,siz[be])if (b[be][j].v==0){b[be][j].sum=add(b[be][j].sum,f[i-1]);break;}
		add(lst[a[i]].se+1,lst[a[i]].fi,-1);
		add(lst[a[i]].fi+1,i,1);
		lst[a[i]].se=lst[a[i]].fi;
		lst[a[i]].fi=i;
		fo(j,1,(n-1)/blk+1)f[i]=f[i]+sum[j];
		f[i]=f[i]%mo;
	}
	cout<<f[n]<<endl;
	return 0;
}