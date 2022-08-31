#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 205
char s[MAXN];int len;
int n,ii,e,t;
int main(){
	scanf("%s",s+1);len=strlen(s+1);
	rep(i,1,len){
		if(s[i]=='n')n++;
		if(s[i]=='i')ii++;
		if(s[i]=='e')e++;
		if(s[i]=='t')t++;
	}
	int ans=len+1;
	ans=min(ans,(n-1)/2);
	ans=min(ans,e/3);
	ans=min(ans,min(t,ii));
	printf("%d\n",ans);
	return 0;
}