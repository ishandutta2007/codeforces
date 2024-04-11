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

const int N=200000+19;
const int oo=(1<<30)-1;

int A[N],x[N],y[N],l[N],r[N],stk[N];
int las[30];
int n,top;
ll ans;

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	for (int i=1;i<=n;i++){
		x[i]=0;
		For(j,0,30) if (!(A[i]>>j&1)) x[i]=max(x[i],las[j]);
		For(j,0,30) if (A[i]>>j&1) las[j]=i;
	}
	For(j,0,30) las[j]=n+1;
	for (int i=n;i>=1;i--){
		y[i]=n+1;
		For(j,0,30) if (!(A[i]>>j&1)) y[i]=min(y[i],las[j]);
		For(j,0,30) if (A[i]>>j&1) las[j]=i;
	}
	A[0]=A[n+1]=oo;
	stk[top=1]=0;
	For(i,1,n+1){
		while (A[i]>A[stk[top]]) top--;
		l[i]=stk[top];
		stk[++top]=i;
	}
	stk[top=1]=n+1;
	for (int i=n;i>=1;i--){
		while (A[i]>=A[stk[top]]) top--;
		r[i]=stk[top];
		stk[++top]=i;
	}
	For(i,1,n+1){
		x[i]=max(x[i],l[i]);
		y[i]=min(y[i],r[i]);
		ans+=1ll*(i-l[i])*(r[i]-i);
		ans-=1ll*(i-x[i])*(y[i]-i);
	}
	cout<<ans<<endl;
}