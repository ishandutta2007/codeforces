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
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
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

const int N=20000+19;
const db pi=acos(-1.0);

struct Point{
	db x,y;
} P[N],A,V;

typedef Point Vector;

Vector operator - (Point A,Point B){
	return (Vector){A.x-B.x,A.y-B.y};
}
Vector operator * (db k,Vector A){
	return (Vector){k*A.x,k*A.y};
}
Point operator + (Point A,Vector B){
	return (Point){A.x+B.x,A.y+B.y};
}
db cross(Vector A,Vector B){
	return A.x*B.y-A.y*B.x;
}

struct Line{
	Point P;
	Vector V;
};

Point cal(Line A,Line B){
	db k=cross(B.P-A.P,B.V)/cross(A.V,B.V);
	return A.P+k*A.V;
}

db sum[N],d,mn,res;
int a,b,n,q;

inline int find(bool b,bool f){
	int l=1,r=n-1,res=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if ((cross(V,P[mid]-A)<=0)==b){
			res=mid;
			if (f) r=mid-1;else l=mid+1;
		} else{
			if (cross(P[mid]-A,P[0]-A)>0) l=mid+1;else r=mid-1;
		}
	}
	return res;
}
db check(db d){
	db s1,s2;
	Point P1,P2;
	V=(Vector){cos(d),sin(d)};
	if (cross(V,P[0]-A)>0){
		a=find(1,1);
		b=find(1,0);
	} else{
		a=find(0,1);
		b=find(0,0);
	}
	P1=cal((Line){P[a-1],P[a]-P[a-1]},(Line){A,V});
	P2=cal((Line){P[b],P[b+1]-P[b]},(Line){A,V});
	s1=sum[b-1]-sum[a-1];
	s1+=cross(P1,P[a]-P1);
	s1+=cross(P[b],P2-P[b]);
	s1+=cross(P2,P1-P2);
	s1=fabs(s1);
	/*
	s2=sum[a+n-2]-sum[b];
	s2+=cross(P2,P[b+1]-P2);
	s2+=cross(P[a+n-1],P1-P[a+n-1]);
	s2+=cross(P1,P2-P1);
	s2=fabs(s2);
	*/
	s2=fabs(sum[n-1])-s1;
	if (cross(V,P[0]-A)<=0) swap(s1,s2);
	return (s1-s2)/fabs(sum[n-1]);
}

int main(){
	n=IN(),q=IN();
	For(i,0,n){
		P[i]=P[i+n]=(Point){IN(),IN()};
	}
	For(i,0,2*n){
		sum[i]=(!i?0:sum[i-1])+cross(P[i],P[(i+1)%(2*n)]-P[i]);
	}
	while (q--){
		A=(Point){IN(),IN()};
		db l=0,r=pi;
		if (check(0)<check(pi)){
			For(T,0,50){
				db mid=(l+r)/2;
				if (check(mid)>=0) r=mid;else l=mid;
			}
		} else{
			For(T,0,50){
				db mid=(l+r)/2;
				if (check(mid)>=0) l=mid;else r=mid;
			}
		}
		res=l;
		mn=check(l);
		printf("%.20lf\n",res);
	}
}