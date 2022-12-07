#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
#define R N[x].right
#define L N[x].left

int n,a[222222],tt,xx,yy,m,kk,u[222222];
pair<int,int>qq[222222];

struct node{
	int left,right;
	int xkor,lkor,rkor,pr;
	long long sum,sl,sr,kol;
}N[222222];

int make(int x){
	kk++;
	N[kk].left=N[kk].right=0;
	N[kk].xkor=N[kk].lkor=N[kk].rkor=x;
	N[kk].kol=1;
	N[kk].pr=rand();
	N[kk].sum=N[kk].sl=N[kk].sr=0;
	return kk;
}

void up(int x){
	if (x==0)return;
	N[x].lkor=N[x].rkor=N[x].xkor;
	N[x].sum=0;
	N[x].kol=1;
	if (L!=0){
		N[x].lkor=N[L].lkor;
		N[x].kol+=N[L].kol;
		N[x].sum+=N[L].sum;
	}
	if (R!=0){
		N[x].rkor=N[R].rkor;
		N[x].kol+=N[R].kol;
		N[x].sum+=N[R].sum;
	}
	N[x].sr=N[x].rkor-N[x].xkor;
	if (R!=0)N[x].sr+=N[R].sr;
	if (L!=0)N[x].sr+=N[L].sr+N[L].kol*(N[x].rkor-N[L].rkor);
	N[x].sl=N[x].xkor-N[x].lkor;
	if (L!=0)N[x].sl+=N[L].sl;
	if (R!=0)N[x].sl+=N[R].sl+N[R].kol*(N[R].lkor-N[x].lkor);
	
	if (L!=0){
		N[x].sum+=N[L].sr+N[L].kol*(N[x].xkor-N[L].rkor);
	}
	if (R!=0){
		N[x].sum+=N[R].sl+N[R].kol*(N[R].lkor-N[x].xkor);
	}
	if (L!=0&&R!=0){
		N[x].sum+=N[L].sr*N[R].kol;
		N[x].sum+=N[R].sl*N[L].kol;
		N[x].sum+=N[L].kol*N[R].kol*(N[R].lkor-N[L].rkor);
	}
}

int les(int t,int x){
	if (t==0)return 0;
	if (N[t].xkor<x)return N[N[t].left].kol+1+les(N[t].right,x);
	return les(N[t].left,x);
}

void cut(int t,int x,int &t1,int &t2){
	t1=t2=0;
	if(x==0){
		t2=t;
		return;
	}
	if (x==N[t].kol){
		t1=t;
		return;
	}
	int q1,q2;
	if (N[N[t].left].kol>=x){
		cut(N[t].left,x,q1,q2);
		t1=q1;
		N[t].left=q2;
		t2=t;
	}else{
		cut(N[t].right,x-N[N[t].left].kol-1,q1,q2);
		t2=q2;
		N[t].right=q1;
		t1=t;
	}
	up(t);
}

int merge(int t1,int t2){
	if (t2==0&&t1==0)return 0;
	if (t1==0)return t2;
	if (t2==0)return t1;
	if (N[t1].pr<N[t2].pr){
		N[t1].right=merge(N[t1].right,t2);
		up(t1);
		return t1;
	}else{
		N[t2].left=merge(t1,N[t2].left);
		up(t2);
		return t2;
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]),qq[i]=mp(a[i],i);
	sort(qq,qq+n);
	sort(a,a+n);
	for (int i=0;i<n;i++)u[qq[i].S]=i;
	int o=make(a[0]),t1,t2;
	for (int i=1;i<n;i++){
		int t=make(a[i]);
		o=merge(o,t);	
	}
	cin >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&tt,&xx,&yy);
		if (tt==1){
			xx--;
			int h=les(o,a[u[xx]]);
			cut(o,h,t1,o);
			cut(o,1,t2,o);
			o=merge(t1,o);
			a[u[xx]]+=yy;
			N[t2].xkor+=yy;
			N[t2].lkor=N[t2].rkor=N[t2].xkor;
			h=les(o,a[u[xx]]);
			cut(o,h,t1,o);
			o=merge(t2,o);
			o=merge(t1,o);
		}else{
			int h=les(o,yy+1);
			cut(o,h,o,t2);
			h=les(o,xx);
			cut(o,h,t1,o);
			cout << N[o].sum << endl;
			o=merge(t1,o);
			o=merge(o,t2);
		}
	}
	return 0;
}