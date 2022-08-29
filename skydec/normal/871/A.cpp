#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
	int Q;scanf("%d",&Q);
	while(Q--){
		int n;scanf("%d",&n);
		if(n%4==0){
			printf("%d\n",n/4);
		}
		else
		if(n%4==1){
			if(n<9)printf("-1\n");
			else printf("%d\n",(n-9)/4+1);
		}
		else
		if(n%4==2){
			if(n<6)printf("-1\n");
			else printf("%d\n",(n-6)/4+1);
		}
		else{
			if(n<15)printf("-1\n");
			else printf("%d\n",(n-15)/4+2);
		}
	}	
	return 0;
}