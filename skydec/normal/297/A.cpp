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
char a[1005],b[1005];int n,m;
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	scanf("%s",b+1);m=strlen(b+1);
	int cnt1=0;int cnt2=0;
	rep(i,1,n)cnt1+=(a[i]-'0');
	rep(i,1,m)cnt2+=(b[i]-'0');
	cnt1+=(cnt1&1);
	if(cnt1>=cnt2){
		printf("YES\n");
	}
	else printf("NO");
	return 0;
}