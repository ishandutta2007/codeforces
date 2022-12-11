#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<LL,LL> pir;

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

const int N = 1e5+5;
const int mo = 1e9+7;

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}
LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

int n;
int a[N];
int lst[N],nxt[N];
map<int,int>pos;
struct node{
	LL sum[4];//r*x / r*l / l
	LL mul[4];
}sgt[N*2];

void build(int now,int l,int r){
	fo(i,0,2)sgt[now].mul[i]=1;
	sgt[now].sum[0]=1ll*(l+r)*(r-l+1)/2%mo;
	sgt[now].sum[1]=sgt[now].sum[2]=r-l+1;
	if (l==r)return;
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	build(ls,l,mid);
	build(rs,mid+1,r);
}

int sta1[N],top1;
int sta2[N],top2;

pir operator +(pir a,pir b){return make_pair(add(a.first,b.first),add(a.second,b.second));}

void changel(int now,int l,int r,int x,int y,LL v){
	if (x<=l&&r<=y){
		fo(c,1,2){
			sgt[now].sum[c]=sgt[now].sum[c]*v%mo;
			sgt[now].mul[c]=sgt[now].mul[c]*v%mo;
		}
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	fo(c,0,2)
	if (sgt[now].mul[c]!=1){
		LL u=sgt[now].mul[c];
		sgt[now].mul[c]=1;
		sgt[ls].sum[c]=sgt[ls].sum[c]*u%mo;
		sgt[rs].sum[c]=sgt[rs].sum[c]*u%mo;
		sgt[ls].mul[c]=sgt[ls].mul[c]*u%mo;
		sgt[rs].mul[c]=sgt[rs].mul[c]*u%mo;
	}
	if (x<=mid)changel(ls,l,mid,x,y,v);
	if (y>mid)changel(rs,mid+1,r,x,y,v);
	fo(c,0,2)sgt[now].sum[c]=add(sgt[ls].sum[c],sgt[rs].sum[c]);
}

void changer(int now,int l,int r,int x,int y,LL v){
	if (x<=l&&r<=y){
		fo(c,0,1){
			sgt[now].sum[c]=sgt[now].sum[c]*v%mo;
			sgt[now].mul[c]=sgt[now].mul[c]*v%mo;
		}
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	fo(c,0,2)
	if (sgt[now].mul[c]!=1){
		LL u=sgt[now].mul[c];
		sgt[now].mul[c]=1;
		sgt[ls].sum[c]=sgt[ls].sum[c]*u%mo;
		sgt[rs].sum[c]=sgt[rs].sum[c]*u%mo;
		sgt[ls].mul[c]=sgt[ls].mul[c]*u%mo;
		sgt[rs].mul[c]=sgt[rs].mul[c]*u%mo;
	}
	if (x<=mid)changer(ls,l,mid,x,y,v);
	if (y>mid)changer(rs,mid+1,r,x,y,v);
	fo(c,0,2)sgt[now].sum[c]=add(sgt[ls].sum[c],sgt[rs].sum[c]);
}

pir query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return make_pair(dec(sgt[now].sum[0],sgt[now].sum[1]),sgt[now].sum[2]);
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	fo(c,0,2)
	if (sgt[now].mul[c]!=1){
		LL u=sgt[now].mul[c];
		sgt[now].mul[c]=1;
		sgt[ls].sum[c]=sgt[ls].sum[c]*u%mo;
		sgt[rs].sum[c]=sgt[rs].sum[c]*u%mo;
		sgt[ls].mul[c]=sgt[ls].mul[c]*u%mo;
		sgt[rs].mul[c]=sgt[rs].mul[c]*u%mo;
	}
	pir ret=make_pair(0,0);
	if (x<=mid)ret=query(ls,l,mid,x,y);
	if (y>mid)ret=ret+query(rs,mid+1,r,x,y);
	return ret;
}


int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,n){
		lst[i]=pos[a[i]]+1;
		pos[a[i]]=i;
	}
	pos.clear();
	fd(i,n,1){
		nxt[i]=pos[a[i]];
		if (!nxt[i])nxt[i]=n;else nxt[i]--;
		pos[a[i]]=i;
	}
	build(1,1,n);
	int l=1;
	LL ans=0;
	fo(i,1,n){
		l=max(l,lst[i]);
		//l..i
		while(top1&&nxt[sta1[top1]]>=nxt[i]){
			top1--;
			changer(1,1,n,sta1[top1]+1,sta1[top1+1],quickmi(nxt[sta1[top1+1]],mo-2));
		}
		changer(1,1,n,sta1[top1]+1,i,nxt[i]);
		sta1[++top1]=i;
		while(top2&&lst[sta2[top2]]<=lst[i]){
			top2--;
			changel(1,1,n,sta2[top2]+1,sta2[top2+1],quickmi(lst[sta2[top2+1]],mo-2));
		}
		changel(1,1,n,sta2[top2]+1,i,lst[i]);
		sta2[++top2]=i;
		pair<LL,LL>u=query(1,1,n,l,i);
		LL tmp=u.first+u.second*i%mo-1ll*(i+l)*(i-l+1)/2%mo*i%mo;
		tmp=(tmp%mo+mo)%mo;
		ans=add(ans,tmp);
		/*LL ad=0;
		int lef=0,rig=n;
		fd(x,i,1){
			lef=max(lef,lst[x]);
			rig=min(rig,nxt[x]);
			if (lef<=x&&i<=rig)ad=ad+(rig-i)*(x-lef);
		}
		cout<<ad<<" "<<tmp<<endl;*/
	}
	cout<<ans<<endl;
	return 0;
}