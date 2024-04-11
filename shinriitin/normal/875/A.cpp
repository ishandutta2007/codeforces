#include <bits/stdc++.h>

int n;

std::vector<int>ans;

inline bool check(int x){
	if(x<=0)return 0;
	int tmp=x;
	while(tmp){
		x+=tmp%10;
		tmp/=10;	
	}
	return x==n;
}

int main(){
	scanf("%d",&n);
	for(int i=100;i;--i)if(check(n-i))ans.push_back(n-i);
	printf("%d\n",(int)ans.size());
	for(auto&x:ans)printf("%d\n",x);
	return 0;	
}