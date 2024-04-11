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
const int MAXN=5100000;
int sum[MAXN][10];char a[MAXN];
vector<int>get[110000];
int n,q;int cho;bool dao[MAXN];int now[12];
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",a+1);
	rep(l,1,n)if(!dao[l]){
		int i=l;int dir=1;int last=0;
		while(i<=n&&i>=l){
			dao[i]=1;
			if(a[i]>='0'&&a[i]<='9'){
				now[a[i]-'0']++;
				a[i]--;
				last=0;
			}
			else if(a[i]=='>'||a[i]=='<'){
				if(a[i]=='>')dir=1;else dir=-1;
				if(last)a[last]=0;
				last=i;
			}
			cho++;
			get[i].pb(cho);
			rep(j,0,9)sum[cho][j]=now[j];
			i+=dir;
		}
		cho++;
		get[i].pb(cho);
		rep(j,0,9)sum[cho][j]=now[j];
	}
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		int start=get[l][0];
		int a1=lower_bound(get[l-1].begin(),get[l-1].end(),start)-get[l-1].begin();
		if(a1==get[l-1].size())a1=1000000007;else a1=get[l-1][a1];
		
		int a2=lower_bound(get[r+1].begin(),get[r+1].end(),start)-get[r+1].begin();
		if(a2==get[r+1].size())a2=1000000007;else a2=get[r+1][a2];
		
		int end=min(a1,a2);
		rep(i,0,9)printf("%d%c",sum[end-1][i]-sum[start-1][i],i==9?'\n':' ');
	}
	return 0;
}