#include<bits/stdc++.h>
using namespace std;

int n,a[100005];
set<int> b[100005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]].insert(i);
	}
	sort(a,a+n);
	int now=0;
	long long ans=n;
	for(int i=0;i<n;i++){
		int x=a[i];
		set<int>::iterator it=b[x].lower_bound(now);
		if(it==b[x].end()){
			ans+=n-i;now=0;
			it=b[x].lower_bound(now);
		}
		now=*it;b[x].erase(it);
	}
	printf("%I64d\n",ans);
	return 0;
}