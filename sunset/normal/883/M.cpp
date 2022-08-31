#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==c){
		printf("%d",2*(2+abs(b-d)+1));
	} else if(b==d){
		printf("%d",2*(2+abs(a-c)+1));
	} else printf("%d",2*(abs(b-d)+1+abs(a-c)+1));
}