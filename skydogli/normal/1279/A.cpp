#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(c>a+b+1) puts("No");
			else puts("Yes");
	}
	return 0;
}