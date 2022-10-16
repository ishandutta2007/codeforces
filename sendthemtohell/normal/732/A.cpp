#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	int a,b;
	int ans=1;
	scanf("%d%d",&a,&b);
	a%=10;
	int c=a;
	while((a-b)%10!=0 && a%10!=0){
		ans++;
		a+=c;
	}
	cout<<ans;
}