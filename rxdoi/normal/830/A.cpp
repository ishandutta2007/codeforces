#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<string>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
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

const int N=2000+19;
const int oo=2147483647;

int A[N],B[N],vis[N];
int n,k,p,res=oo;

int gao(int x){
	int res=0;
	For(i,1,n+1){
		res=max(res,abs(A[i]-B[i+x-1])+abs(B[i+x-1]-p));
	}
	return res;
}

int main(){
	n=IN(),k=IN(),p=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,k+1) B[i]=IN();
	sort(A+1,A+n+1);
	sort(B+1,B+k+1);
	for (int i=1;i+n-1<=k;i++) res=min(res,gao(i));
	printf("%d\n",res);
}