#include<bits/stdc++.h>
using namespace std;

int calc(int n){
	for(int i=2;i*i<=n;i++)
		if(n%i==0)return n/i;
	return 1;
}

int main(){
	int q,a;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&a);
		int nxt=1;
		while(nxt<a)nxt=nxt*2+1;
		if(nxt==a)
			printf("%d\n",calc(a));
		else
			printf("%d\n",nxt);
	}
	return 0;
}