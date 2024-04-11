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
#define mid (x+y>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int R1,R2,L1,L2,U1,U2,D1,D2;
int r1,r2,l1,l2,u1,u2,d1,d2;
int n,x,y;

int Qry(int U,int L,int D,int R){
	if (U>D) swap(U,D);
	if (L>R) swap(L,R);
	printf("? %d %d %d %d\n",U,L,D,R);
	fflush(stdout);
	return IN();
}
bool chk(int l1,int r1,int l2,int r2){
	return l2<=r1&&r2>=l1;
}
void chk(int a,int b,int c){
	r1=R1,r2=R2,l1=L1,l2=L2;
	u1=U1,u2=U2,d1=D1,d2=D2;
	if (a) swap(d1,d2);
	if (b) swap(l1,l2);
	if (c) swap(r1,r2);
	if (u1>d1||u2>d2||l1>r1||l2>r2) return;
	if (chk(u1,d1,u2,d2)&&chk(l1,r1,l2,r2)) return;
	if (Qry(u1,l1,d1,r1)&&Qry(u2,l2,d2,r2)){
		printf("! %d %d %d %d %d %d %d %d\n",u1,l1,d1,r1,u2,l2,d2,r2);
		fflush(stdout);
		exit(0);
	}
}

int main(){
	n=IN();
	for (x=1,y=n;x<=y;) (Qry(1,1,n,mid)>=1)?(R1=mid,y=mid-1):(x=mid+1);
	for (x=1,y=n;x<=y;) (Qry(1,1,n,mid)>=2)?(R2=mid,y=mid-1):(x=mid+1);
	for (x=1,y=n;x<=y;) (Qry(1,mid,n,n)>=1)?(L2=mid,x=mid+1):(y=mid-1);
	for (x=1,y=n;x<=y;) (Qry(1,mid,n,n)>=2)?(L1=mid,x=mid+1):(y=mid-1);
	for (x=1,y=n;x<=y;) (Qry(1,1,mid,n)>=1)?(D1=mid,y=mid-1):(x=mid+1);
	for (x=1,y=n;x<=y;) (Qry(1,1,mid,n)>=2)?(D2=mid,y=mid-1):(x=mid+1);
	for (x=1,y=n;x<=y;) (Qry(mid,1,n,n)>=1)?(U2=mid,x=mid+1):(y=mid-1);
	for (x=1,y=n;x<=y;) (Qry(mid,1,n,n)>=2)?(U1=mid,x=mid+1):(y=mid-1);
	chk(0,0,0);chk(0,0,1);chk(0,1,0);chk(0,1,1);
	chk(1,0,0);chk(1,0,1);chk(1,1,0);chk(1,1,1);
}