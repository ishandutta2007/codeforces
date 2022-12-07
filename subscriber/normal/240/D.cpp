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

int n,x,y,a[222222],b[222222],e[222222],w[222222],t,l,m,k;

void s0(){
	x=y=0;
	t=0;
	k=0;
	while (x<n||y<m){
		while (x<n&&a[x]==t)e[k]=t,w[k++]=x,x++;
		while (y<m&&b[y]==t)e[k]=t,w[k++]=y+n,y++;
		t^=1;
	}
	e[n+m]=0;
}

void s1(){
	x=y=0;
	t=1;
	k=0;
	while (x<n||y<m){
		while (x<n&&a[x]==t)e[k]=t,w[k++]=x,x++;
		while (y<m&&b[y]==t)e[k]=t,w[k++]=y+n,y++;
		t^=1;
	}
	e[n+m]=0;
}

int f(){
	int s=0,l=-1;
	for (int i=0;i<n+m;i++)if (e[i]==1&&e[i+1]==0){
		if (l==-1)s++;else s+=2;
	}else if (e[i]==0)l=i;
	return s;
}

int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	cin >> m;
	for (int i=0;i<m;i++)scanf("%d",&b[i]);
	s0();
	int tt=f();
	s1();
	if (f()>tt)s0();
	for (int i=0;i<n+m-1;i++)printf("%d ",w[i]+1);
	CC(w[n+m-1]+1);
	CC(f());
	int l=-1;
	for (int i=0;i<n+m;i++)if (e[i]==1&&e[i+1]==0){
		if (l!=-1)cout << l+1 << " ";
		cout << i+1 << " ";
	}else if (e[i]==0)l=i;
	return 0;
}