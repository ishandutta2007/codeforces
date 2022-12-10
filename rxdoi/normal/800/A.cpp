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

const int N=100000+19;

int A[N],B[N];
int n,p;
ll sum;
db l,r;

bool check(db T){
	db tmp=0;
	For(i,1,n+1) tmp+=max(T*A[i]-B[i],0.0);
	return tmp<=T*p;
}

int main(){
	n=IN(),p=IN();
	For(i,1,n+1){
		A[i]=IN(),B[i]=IN();
		sum+=A[i];
	}
	if (sum<=p){
		puts("-1");
		return 0;
	}
	l=0,r=1e18;
	For(i,0,100){
		db mid=(l+r)/2.0;
		if (check(mid)) l=mid;else r=mid;
	}
	printf("%.10lf\n",l);
}