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

const int N=1e5+19;

int F[2][1<<10];
int A[N];
int n,k,x,t;

int main(){
	n=IN();k=IN(),x=IN();
	For(i,1,n+1) F[t][IN()]++;
	For(i,0,k){
		memset(F[t^1],0,sizeof(F[t^1]));
		int c=0;
		For(j,0,1<<10){
			if (c%2==0){
				F[t^1][j^x]+=F[t][j]-F[t][j]/2;
				F[t^1][j]+=F[t][j]/2;
			} else{
				F[t^1][j^x]+=F[t][j]/2;
				F[t^1][j]+=F[t][j]-F[t][j]/2;
			}
			c+=F[t][j];
		}
		t^=1;
	}
	For(j,0,1<<10) For(i,0,F[t][j]) A[++*A]=j;
	sort(A+1,A+*A+1);
	printf("%d %d\n",A[n],A[1]);
}