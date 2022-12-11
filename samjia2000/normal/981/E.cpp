#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int N = 1e4+5;

int n,q;
struct operate{
	int l,r,x;
}op[N];
bitset<N>now[20],ans;

void solve(int l,int r,int lq,int rq,int dep){
	if (lq>rq)return;
	fo(i,lq,rq)
	if (op[i].l<=l&&op[i].r>=r)now[dep]=now[dep]|(now[dep]<<op[i].x);
	ans=ans|now[dep];
	if(l==r)return;
	int mid=(l+r)/2;
	int he=lq,ta=rq;
	fo(i,lq,rq)
	if (!(op[i].l<=l&&op[i].r>=r)){
		if (op[i].l<=mid)swap(op[i],op[he++]);
	}
	now[dep+1]=now[dep];
	solve(l,mid,lq,he-1,dep+1);
	fd(i,rq,lq)
	if (!(op[i].l<=l&&op[i].r>=r)){
		if (op[i].r>mid)swap(op[i],op[ta--]);
	}
	now[dep+1]=now[dep];
	solve(mid+1,r,ta+1,rq,dep+1);
}

int main(){
	n=get();q=get();
	fo(i,1,q){op[i].l=get();op[i].r=get();op[i].x=get();}
	ans.reset();
	fo(i,0,19)now[i].reset();
	now[0][0]=1;
	solve(1,n,1,q,0);
	int k=0;
	fo(i,1,n)if (ans[i])k++;
	printf("%d\n",k);
	fo(i,1,n)if (ans[i])printf("%d ",i);
	putchar('\n');
	return 0;
}