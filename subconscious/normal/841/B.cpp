#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 1000005
using namespace std;
int a[N],n;bool q;
int main(){
	scanf("%d",&n);q=0;
	rep(i,n){
		scanf("%d",a+i);
		if(a[i]&1)q=1;
	}
	if(q)puts("First");else puts("Second");
	//if(p&1==0)puts("Second");else puts("First");
	return 0;
}