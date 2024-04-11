#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define jsb 4294967296ll
#define MAXN 110000
int bi=0;unsigned int f[MAXN];
char c[MAXN];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s",c);
	f[0]=1;int c1=0;
	rep(i,0,n-1)if(c[i]=='?')c1++;
	if((n&1)||(c1<n/2)){printf("0\n");return 0;}c1-=(n/2);
	rep(i,0,n-1)if(c[i]=='?'){
		for(int j=(i+1)/2;j&&j>i-(n/2);j--)f[j]+=f[j-1];
	}
	rep(i,1,c1)f[n/2]*=25;
	printf("%u\n",f[n/2]);
	return 0;
}