#include <bits/stdc++.h>

const int max_N = 1e6 + 21;

bool vis[max_N];

int main(){
	vis[0]=1;
	for(int i=1;i*i<=(int)1e6;++i)
		vis[i*i]=1;
	int res=-(0x3f3f3f3f),n,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(x<0||!vis[x])res=std::max(res,x);
	}
	printf("%d\n",res);
	return 0;
}