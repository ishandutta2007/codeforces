#include<bits/stdc++.h>
using namespace std;
char a[][20]={"one","two","three","four","five","six","seven","eight","nine","ten"},
b[][20]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"},
c[][20]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int n;

main(){
	scanf("%d",&n);
	if(!n) puts("zero");
	else if(n < 10) printf("%s\n",a[n-1]);
	else if(n == 10) puts("ten");
	else if(n < 20) printf("%s\n",b[n-11]);
	else if(n % 10 == 0) printf("%s\n",c[n/10-2]);
	else printf("%s-%s\n",c[n/10-2],a[n%10-1]);
}