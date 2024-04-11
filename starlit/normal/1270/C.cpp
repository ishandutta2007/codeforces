#include<bits/stdc++.h>
using namespace std;
int T,n,x;
long long S,X;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);S=X=0;
		for(int i=0;i<n;i++)
		scanf("%d",&x),S+=x,X^=x;
		printf("2 %lld %lld\n",X,S+X);
	}
}