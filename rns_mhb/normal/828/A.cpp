#include<bits/stdc++.h>
using namespace std;

int n, a, b, t, ans, c;

main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i = 0;i < n;i ++){
		scanf("%d",&t);
		if(t == 2 && b) b --;
		else if(t == 1 && a > 0) a --;
		else if(t == 1 && !a && b > 0) b --,c ++;
		else if(t == 1 && !a && !b && c > 0) c --;
		else if(t == 1 && !a && !b && !c) ans ++;
		else if(t == 2 && !b) ans += 2;
	}
	printf("%d",ans);
}