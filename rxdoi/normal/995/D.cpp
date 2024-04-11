#include<bits/stdc++.h>

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

const int N=1<<18;

int A[N];
int n,r,x,y;
db sum;

int main(){
	n=IN(),r=IN();
	For(i,0,1<<n){
		A[i]=IN();
		sum+=A[i];
	}
	printf("%.10lf\n",sum/(1<<n));
	For(i,0,r){
		x=IN(),y=IN();
		sum-=A[x];
		A[x]=y;
		sum+=A[x];
		printf("%.10lf\n",sum/(1<<n));
	}
}