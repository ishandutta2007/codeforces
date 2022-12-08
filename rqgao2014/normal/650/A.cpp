#include<bits/stdc++.h>
using namespace std;

int n,u[200005],v[200005];
long long ans;
map<int,int> num;
map<pair<int,int>,int> num2;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=n;i++){
		ans+=num[u[i]];
		num[u[i]]++;
	}
	num.clear();
	for(int i=1;i<=n;i++){
		ans+=num[v[i]];
		num[v[i]]++;
	}
	for(int i=1;i<=n;i++){
		ans-=num2[make_pair(u[i],v[i])];
		num2[make_pair(u[i],v[i])]++;
	}
	printf("%lld\n",ans);
}
/*
2
1 1
1 1
*/