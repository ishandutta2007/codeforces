#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int n;
const int N=110000;
char a[N],b[N];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	while(a[n]==b[n]&&n)n--;
	int m=1;
	while(a[m]==b[m])m++;
	if(m==n){
		printf("2\n");
		return 0;
	}
	bool fl=1;
	rep(i,m+1,n)fl&=(a[i]==b[i-1]);
	int ret=0;
	if(fl)ret++;
	fl=1;
	rep(i,m,n-1)fl&=(a[i]==b[i+1]);
	if(fl)ret++;
	
	printf("%d\n",ret);
	return 0;
}