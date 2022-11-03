#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,v[N],t[N];
long long s[N];
priority_queue<long long> q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+t[i];
	int now=0;
	for(int i=1;i<=n;i++){
		q.push(-(v[i]+s[i-1]));
		now++;
		long long ans=0;
		for(;!q.empty();){
			long long u=-q.top();
			if(u>=s[i])break;
			q.pop();
			ans+=u-s[i-1];
			now--;
		}
		ans+=1ll*now*t[i];
		printf("%lld ",ans);
	}
	return 0;
}