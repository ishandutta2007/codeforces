#include<bits/stdc++.h>
using namespace std;

bool vis[1000005];
int n;

int gen(int l,int r){
	std::mt19937 e(19260817^(size_t)new char);
	std::uniform_int_distribution<> g(l,r);
	return g(e);
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	scanf("%d",&n);
	int l=0,r=1000000000;
	while(l<r){
		int mid=l+r>>1;
		printf("> %d\n",mid);
		fflush(stdout);
		int ret;
		scanf("%d",&ret);
		if(ret==1)l=mid+1;
		else r=mid;
	}
	int ma=l,d=0;
	for(int i=1;i<=min(n,29);i++){
		int pos=gen(1,n);
		while(vis[pos])pos=gen(1,n);
		printf("? %d\n",pos);
		vis[pos]=true;
		fflush(stdout);
		int ret;
		scanf("%d",&ret);
		d=gcd(d,ma-ret);
	}
	int a1=ma-d*(n-1);
	printf("! %d %d\n",a1,d);
	return 0;
}