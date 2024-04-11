#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,a[N],b[N],p[N],f[N],n,k;
const LL MOD=998244353;

int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)p[i]=f[i]=0;

		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);p[a[i]]=i;
		}
		set<int> st;
		for(int i=1;i<=k;i++){
			scanf("%d",&b[i]);f[p[b[i]]]=1;
			st.insert(p[b[i]]);
		}

		LL ans=1;

		for(int i=1;i<=k;i++){
			int pos=p[b[i]];
			//printf("i=%d,pos=%d\n", i,pos);
			int ways=0;
			if(pos+1==n+1 || st.count(pos+1)){}else ways++;
			if(pos-1==0 || st.count(pos-1)){}else ways++;
			st.erase(pos);
			//printf("ways=%d\n", ways);
			ans=ans*ways%MOD;
		}
		printf("%lld\n", ans);
    }
}