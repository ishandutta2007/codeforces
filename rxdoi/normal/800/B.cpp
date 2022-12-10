#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__V_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1000+19;

struct Point{
	db x,y;
} P[N];
typedef Point Vector;

Vector operator - (Point A,Point B) {return (Vector){A.x-B.x,A.y-B.y};}
db cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}
db dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}

int n;
db res;

db calc(Point A,Point B,Point C){
	return cross(C-B,B-A)/sqrt(dot(C-A,C-A))/2;
}

int main(){
	n=IN();
	For(i,0,n) P[i]=(Point){IN(),IN()};
	res=1e60;
	For(i,0,n) res=min(res,calc(P[i],P[(i+1)%n],P[(i+2)%n]));
	printf("%.10lf\n",res);
}