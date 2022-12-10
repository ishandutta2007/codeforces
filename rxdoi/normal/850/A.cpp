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

const int N=1000+19;

struct Point{
	int a,b,c,d,e;
} P[N];
typedef Point Vector;

Vector operator - (Point A,Point B){
	return (Vector){A.a-B.a,A.b-B.b,A.c-B.c,A.d-B.d,A.e-B.e};
}
ll dot(Vector A,Vector B){
	return A.a*B.a+A.b*B.b+A.c*B.c+A.d*B.d+A.e*B.e;
}

int n;
Vi res;

int main(){
	n=IN();
	For(i,1,n+1){
		P[i]=(Point){IN(),IN(),IN(),IN(),IN()};
	}
	if (n>32){
		puts("0");
		return 0;
	}
	For(i,1,n+1){
		bool b=1;
		For(j,1,n+1) if (j!=i){
			For(k,j+1,n+1) if (k!=i){
				if (dot(P[j]-P[i],P[k]-P[i])>0){
					b=0;
				}
			}
		}
		if (b) res.pb(i);
	}
	printf("%d\n",int(res.size()));
	For(i,0,res.size()) printf("%d ",res[i]);
	puts("");
}