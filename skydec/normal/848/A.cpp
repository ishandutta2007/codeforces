#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
	int k;scanf("%d",&k);
	if(!k){
		puts("a");
		return 0;
	}
	char d='a';
	per(i,400,2)if(i*(i-1)/2<=k){
		k-=(i*(i-1))/2;
		rep(j,1,i)putchar(d);
		d++;
	}
	while(k){
		k--;
		putchar(d);putchar(d);
		d++;
	}
	return 0;
}