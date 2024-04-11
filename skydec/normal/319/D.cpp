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
#define MAXN 51000
char str[MAXN];int n;char a[MAXN];
int main(){
	int m=0;scanf("%s",str+1);n=strlen(str+1);
	rep(i,1,n)if(str[i]!=str[i-1])a[++m]=str[i];
	n=m;
	int now=2;
	while(now<=n/2){
		int u=0;bool f=0;
		int i=1;
		for(;i<=n-now;i++)
		{
			if(a[i]==a[i+now]){
				u++;
			}
			else u=0;
			if(u==now){f=1;break;}
		}
		if(!f)now++;else{
			rep(j,i,n-now)a[j]=a[j+now];
			n-=now;
		}
	}
	rep(i,1,n)putchar(a[i]);
	return 0;
}