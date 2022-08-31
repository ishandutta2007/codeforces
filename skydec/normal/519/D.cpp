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
const int N=110000;
LL sum[N];int pa[30];int n;
map<LL,int> mp[30];char a[N];
int main(){
	rep(i,0,25)scanf("%d",&pa[i]);
	scanf("%s",a+1);LL sp=0;LL ans=0;n=strlen(a+1);
	rep(i,1,n){
		//printf("%I64d\n",sp);
		ans+=mp[a[i]-'a'][sp];
		sp+=1ll*pa[a[i]-'a'];
		mp[a[i]-'a'][sp]++;
	}
	printf("%I64d\n",ans);
	return 0;
}