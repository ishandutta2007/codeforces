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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,m,x,o,l,q1,q2,qx[3333],qo[3333],ql[3333],w[1111][2];
char a[1111][1111];

void add(int x,int o,int l){
	if (o==0&&x==n-1){
		CC(l);
		exit(0);	 	
	}
	if (w[x][o])return;
	w[x][o]=1;
	qx[q1]=x;
	qo[q1]=o;
	ql[q1++]=l;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++)gets(a[i]);
	add(0,0,0);
	while (q1!=q2){
		x=qx[q2];
		o=qo[q2];
		l=ql[q2++];
		if (o==0){
			for (int i=0;i<m;i++)if (a[x][i]=='#')add(i,1,l+1);
		}else for (int i=0;i<n;i++)if (a[i][x]=='#')add(i,0,l+1);
	}
	puts("-1");
	return 0;
}