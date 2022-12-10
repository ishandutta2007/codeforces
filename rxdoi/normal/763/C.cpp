#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

int Pow(int a,int b,int p){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

map<int,int> M;
int m,n,flg,x,d,tmp,cnt,num,now;
int A[N],vis[2*N];

void Work(){
	if (n==1){
		x=A[1];
		d=1;
		return;
	}
	tmp=(A[2]-A[1]+m)%m;
	For(i,1,n+1) M[A[i]]=1;
	For(i,1,n+1){
		if (M.count((A[i]+tmp)%m)) cnt++;
	}
	cnt=n-cnt;
	d=1ll*tmp*Pow(cnt,m-2,m)%m;
	num=1;x=A[1];
	for (now=(A[1]-d+m)%m;;now=(now-d+m)%m){
		if (!M.count(now)) break;
		num++,x=now;
	}
	for (now=(A[1]+d)%m;;now=(now+d)%m){
		if (!M.count(now)) break;
		num++;
	}
	if (num!=n){
		puts("-1");
		exit(0);
	}
}

int main(){
	m=IN(),n=IN();
	For(i,1,n+1) A[i]=IN();
	if (n==m){
		printf("%d %d\n",0,1);
		return 0;
	}
	if (n>m-n){
		For(i,1,n+1) vis[A[i]]=1;
		n=0;
		For(i,0,m) if (!vis[i]) A[++n]=i;
		flg=1;
	}
	Work();
	if (flg){
		printf("%d %d\n",(x-d+m)%m,m-d);
	} else{
		printf("%d %d\n",x,d);
	}
}