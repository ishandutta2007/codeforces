#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main(){
	scanf("%d%d%d",&a,&b,&n);
	a=min(a,n),b=min(b,n);
	printf("%d",b-(n-a)+1);
}