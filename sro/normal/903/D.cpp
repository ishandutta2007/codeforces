#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
map<int,int> lss;
int cnt[600005];
int cntt=0;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		lss[a[i]];
		lss[a[i]-1];
		lss[a[i]+1];
	}
	for(map<int,int>::iterator it=lss.begin();it!=lss.end();it++){
		it->second=++cntt;
	}
	long double sum=0,ans=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*a[i]*(i-1)-sum;
		int dy=lss[a[i]];
		ans+=cnt[dy+1];
		ans-=cnt[dy-1];
		sum+=a[i];
		cnt[dy]++;
	}
	printf("%.0Lf\n",ans);
	return 0;
}