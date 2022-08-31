#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(i=(j);i<=(k);i++)
#define per(i,j,k) for(i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 210000
using namespace std;
int n;int a[MAXN],b[MAXN],key[MAXN];
int i;
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){scanf("%d",&b[i]);key[b[i]]=i;}
	rep(i,1,n)a[i]=key[a[i]];
	rep(i,1,n)if(a[i]<a[i-1]){
		printf("%d\n",n-i+1);
		return 0;
	}
	printf("0\n");
	return 0;
}