#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
#include<bitset>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';
	return !f?x:-x;
}

const int N=100000+19;

int A[2*N];
int n;
ll ans;

int main(){
	n=IN();
	For(i,1,2*n+1) A[i]=IN();
	sort(A+1,A+2*n+1);
	ans=1ll*(A[n]-A[1])*(A[2*n]-A[n+1]);
	for (int i=2;i<=n;i++){
		ans=min(ans,1ll*(A[i+n-1]-A[i])*(A[2*n]-A[1]));
	}
	cout<<ans<<endl;
}