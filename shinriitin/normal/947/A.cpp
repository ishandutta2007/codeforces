#include <bits/stdc++.h>

const int max_N = 1e6 + 21;

bool vis[max_N];

int n,min[max_N];

std::vector<int>p;

void init(int n){
	for(int x=2;x<=n;++x){
		if(!vis[x]){
			p.push_back(x);
			min[x]=x;
		}
		for(auto&y:p){
			if(1ll*x*y>n)break;
			vis[x*y]=1; min[x*y]=y;
			if(x%y==0)break;
		}
	}
}

int ans=0x3f3f3f3f;

int max(int n){
	while(n!=min[n])n/=min[n];
	return n;
}

int calc(int x){
	int tmp=x,res=0x3f3f3f3f;
	while(tmp!=1){
		res=std::min(res,std::max(min[tmp]*(x/min[tmp]-1),min[tmp])+1);
		tmp/=min[tmp];
	}
	return res;
}

int main(){
	scanf("%d",&n);
	init(n);
	for(int i=n-max(n)+1;i<=n;++i)
		if(vis[i]){
			ans=std::min(ans,calc(i));
		}
	printf("%d\n",ans);
	return 0;
}