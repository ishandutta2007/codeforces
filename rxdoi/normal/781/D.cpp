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

const int N=500+19;

ll res;
int n,m,c,x,y,z;

struct Matrix{
	bitset<N> s[N];
} tmp,P[64],V[64],now,alb;

Matrix operator * (const Matrix &A,const Matrix &B){
	For(i,1,n+1) tmp.s[i].reset();
	For(i,1,n+1) For(k,1,n+1)
		if (A.s[i][k]){
			tmp.s[i]|=B.s[k];
		}
	return tmp;
}

int main(){
	n=IN(),m=IN();
	For(i,0,m){
		x=IN(),y=IN(),z=IN();
		if (!z) P[0].s[x][y]=1;else V[0].s[x][y]=1;
	}
	For(i,1,64){
		P[i]=P[i-1]*V[i-1];
		V[i]=V[i-1]*P[i-1];
	}
	For(i,1,n+1) now.s[i][i]=1;
	for (int i=61;~i;i--){
		alb=now*(!c?P[i]:V[i]);
		if (alb.s[1].count()) now=alb,c^=1,res|=1ll<<i;
	}
	if (res>ll(1e18)) return puts("-1"),0;
	cout<<res<<endl;
}