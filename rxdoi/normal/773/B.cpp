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

const int N=120+19;

int A[N][5],cnt[5],val[5];
int n,l,r,m,res;

int cal(int x){
	int res=0;
	For(i,0,5)
		if (~A[x][i]){
			res+=val[i]-val[i]*A[x][i]/250;
		}
	return res;
}
bool check(int x){
	memset(cnt,0,sizeof(cnt));
	For(i,1,n+1){
		For(j,0,5) if (~A[i][j]) cnt[j]++;
	}
	For(i,0,5){
		if (~A[1][i]&&~A[2][i]&&A[1][i]>A[2][i]) cnt[i]+=x;
	}
	For(i,0,5){
		if (32ll*cnt[i]<=n+x) val[i]=3000;
		lf (16ll*cnt[i]<=n+x) val[i]=2500;
		lf (8ll*cnt[i]<=n+x) val[i]=2000;
		lf (4ll*cnt[i]<=n+x) val[i]=1500;
		lf (2ll*cnt[i]<=n+x) val[i]=1000;
		else val[i]=500;
	}
	return cal(1)>cal(2);
}

int main(){
	n=IN();
	For(i,1,n+1) For(j,0,5) A[i][j]=IN();
	For(i,0,100*n+1){
		if (check(i)){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("%d\n",-1);
}