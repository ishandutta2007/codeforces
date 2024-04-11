#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T> void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
int n,a[2005];
void solve(){
	scanf("%d",&n);int sum=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum^=a[i];
	if(!sum) return puts("YES"),void();int cnt=0;
	for(int i=1,cur=0;i<=n;i++){
		cur^=a[i];if(cur==sum) cnt++,cur=0;
	}
	if(cnt>=3) puts("YES");
	else puts("NO");
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}