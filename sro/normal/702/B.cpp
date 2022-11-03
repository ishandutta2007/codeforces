#include <bits/stdc++.h>
using namespace std;

int n;
map<int,int> cnt;

int main(){
	scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		for(int j=0;j<=30;j++){
			ans+=cnt[(1<<j)-a];
		}
		cnt[a]++;
	}
	printf("%lld\n",ans);
	return 0;
}