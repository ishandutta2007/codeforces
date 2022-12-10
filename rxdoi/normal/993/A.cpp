#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lf else if

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

const int oo=(1<<30)-1;

map<int,map<int,int> > vis;
int X1,X2,Y1,Y2;
int A1,A2,B1,B2;
int x,y,a,b;

int main(){
	X1=oo,X2=-oo;
	Y1=oo,Y2=-oo;
	A1=oo,A2=-oo;
	B1=oo,B2=-oo;
	For(i,0,4){
		x=IN(),y=IN();
		X1=min(X1,x);
		X2=max(X2,x);
		Y1=min(Y1,y);
		Y2=max(Y2,y);
	}
	For(i,0,4){
		a=IN(),b=IN();
		A1=min(A1,a);
		A2=max(A2,a);
		B1=min(B1,b);
		B2=max(B2,b);
	}
	a=(A1+A2)/2;
	b=(B1+B2)/2;
	For(i,A1,A2+1) For(j,B1,B2+1){
		if (abs(i-a)+abs(j-b)<=(A2-A1)/2) vis[i][j]=1;
	}
	For(i,X1,X2+1) For(j,Y1,Y2+1)
		if (vis[i][j]){
			puts("YES");
			return 0;
		}
	puts("NO");
}