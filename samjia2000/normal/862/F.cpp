#include<algorithm>
#include<cstdio>
#include<iostream>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

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

const int N = 1e5+5;
const int L = 150;

int n,q;
int Pre;
int Mxlen;
char s[N],T[N];
int st[N],len[N];
int lcp[N];
struct node{
	int pre,suf,val;
}tree[N*L*2];
int rt[L];
int Ex;

void change(int now,int l,int r,int x,int v){
	if (l==r){
		tree[now].pre=tree[now].suf=tree[now].val=v;
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	if (x<=mid)change(ls,l,mid,x,v);
	else change(rs,mid+1,r,x,v);
	tree[now].val=max(max(tree[ls].val,tree[rs].val),tree[ls].suf+tree[rs].pre);
	tree[now].pre=tree[ls].pre;
	if (tree[now].pre==mid-l+1)tree[now].pre+=tree[rs].pre;
	tree[now].suf=tree[rs].suf;
	if (tree[now].suf==r-mid)tree[now].suf+=tree[ls].suf;
}

int ans_pre,ans_suf,ans_val;

void query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y){
		if(ans_val==-1)ans_pre=tree[now].pre,ans_suf=tree[now].suf,ans_val=tree[now].val;
		else{
			ans_val=max(ans_val,max(tree[now].val,ans_suf+tree[now].pre));
			if(tree[now].suf==r-l+1)ans_suf+=tree[now].suf;
			else ans_suf=tree[now].suf;
		}
		return;
	}
	int mid=(l+r)/2;
	int ls=now+1,rs=now+(mid-l+1)*2;
	if (x<=mid)query(ls,l,mid,x,y);
	if (y>mid)query(rs,mid+1,r,x,y);
}

int be[N];
int rig[N],lef[N];
int Mx;
int sta[N];
int val[N];
int ans[N];

int solve(int L,int R){
	if (L>R)return 0;
	int ret=0;
	int top=0;
	fo(i,L,R){
		int lst=0;
		while(top&&val[sta[top]]>=lcp[i]){
			lst=sta[top];
			ret=max(ret,(i-lst)*val[lst]);
			val[lst]=lcp[i];
			top--;
		}
		val[i]=len[i];
		if (lst){
			sta[++top]=lst;
			if (val[i]>val[lst])sta[++top]=i;
		}
		else sta[++top]=i;
	}
	fo(i,1,top)ret=max(ret,(R-sta[i]+1)*val[sta[i]]);
	return ret;
}

void rebuild(int B){
	if (!B||B>Mx)return;
	int R=rig[B],L=max(1,R-Ex*2+1);
	ans[B]=solve(L,R);
}

int query(int l,int r){
	if (l==r)return len[l];
	int ret=0;
	fo(i,1,Mxlen){
		ans_pre=ans_suf=ans_val=-1;
		query(rt[i],1,n,l+1,r);
		if (ans_val>0)ret=max(ret,(ans_val+1)*i);
		else break;
	}
	fo(i,be[l]+2,be[r]-1)ret=max(ret,ans[i]);
	ret=max(ret,solve(l,min(r,l+Ex*2-1)));
	ret=max(ret,solve(max(l,r-Ex*2+1),r));
	return ret;
}

void getlcp(int x){
	if (x>n||x<2)return;
	fo(i,1,min(lcp[x],Mxlen))change(rt[i],1,n,x,0);
	lcp[x]=0;
	while(lcp[x]<min(len[x],len[x-1])&&s[st[x]+lcp[x]]==s[st[x-1]+lcp[x]])lcp[x]++;
	fo(i,1,min(lcp[x],Mxlen))change(rt[i],1,n,x,1);
}

void change_str(int x){
	scanf("%s",T+1);
	len[x]=strlen(T+1);
	st[x]=Pre+1;
	fo(i,1,len[x])s[Pre+i]=T[i];
	Pre+=len[x];
	getlcp(x);
	getlcp(x+1);
	rebuild(be[x]);
	rebuild(be[x]+1);
	if (be[x+1]!=be[x])rebuild(be[x]+2);
}

int main(){
	n=get();q=get();
	Mxlen=sqrt(100000.0/(log(100000)/log(2)))*1.2;
	Ex=100000/Mxlen+1;
	fo(i,1,n){
		scanf("%s",s+Pre+1);
		st[i]=Pre+1;
		len[i]=strlen(s+Pre+1);
		Pre+=len[i];
	}
	rt[1]=1;
	fo(i,2,Mxlen)rt[i]=rt[i-1]+n*2-1;
	fo(i,2,n){
		lcp[i]=0;
		while(lcp[i]<min(len[i],len[i-1])&&s[st[i]+lcp[i]]==s[st[i-1]+lcp[i]])lcp[i]++;
		fo(x,1,min(lcp[i],Mxlen))change(rt[x],1,n,i,1);
	}
	rig[Mx=1]=Ex*2;
	for(;rig[Mx]<n;Mx++)rig[Mx+1]=rig[Mx]+Ex;
	rig[Mx]=n;
	fo(i,1,Mx)rebuild(i);
	fo(i,1,rig[1])be[i]=1;
	fo(i,2,Mx)fo(x,rig[i-1]+1,rig[i])be[x]=i;
	fo(cas,1,q){
		int ty=get();
		if (ty==1){
			int l=get(),r=get();
			printf("%d\n",query(l,r));
		}
		else{
			int x=get();
			change_str(x);
		}
	}
	return 0;
}