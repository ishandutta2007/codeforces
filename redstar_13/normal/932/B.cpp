#include <bits/stdc++.h>
using namespace std;
#define NN 1000010

int E[NN][10];
int f(int x){
	if(x<10) return x;
	int p=1;
	while(x){
		if(x%10!=0)p*=x%10;
		x/=10;
	}
	return f(p);
}
int g(int n){
	if(n<10) return n;
	return f(n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	for(int j=1;j<NN;j++)
		for(int i=1;i<=9;i++){
			E[j][i]=E[j-1][i];
			if(g(j)==i) E[j][i]++;
		}
	int d,l,r,k;
	scanf("%d",&d);
	while(d--){
		scanf("%d%d%d",&l,&r,&k);
		int t=E[r][k]-E[l-1][k];
		
		printf("%d\n",t);
	}
	return 0; 
}