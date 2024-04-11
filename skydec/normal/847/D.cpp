#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
int t[N],n,T;
map<int,int>mp;
int main(){
	scanf("%d%d",&n,&T);
	rep(i,1,n)scanf("%d",&t[i]);
	T--;
	int ans=0;
	int now=0;
	rep(x,1,n){
		if(x>T)break;
		if(t[x]<=T){
			mp[T+x-t[x]]++;
			if(T+x-t[x]>=x)++now;
			ans=max(ans,now);
		}
		now-=mp[x];
	}
	printf("%d\n",ans);
	return 0;
}