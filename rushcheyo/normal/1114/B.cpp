#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200005;
int n,m,k,a[N],id[N];
bool ok[N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i),id[i]=i;
	sort(id+1,id+1+n,[](int p,int q){return a[p]>a[q];});
	ll ans=0;
	for(int i=1;i<=k*m;i++)ok[id[i]]=true,ans+=a[id[i]];
	printf("%lld\n",ans);
	int cnt=0,con=0;
	for(int i=1;i<=n;i++)
		if(ok[i]&&++cnt==m&&i!=n){
			cnt=0,printf("%d ",i);
			if(++con==k-1)break;
		}
}