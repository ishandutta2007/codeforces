#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n&1){
		puts("YES");
		for(int i=0;i<n;i++)
		printf("%d ",2*i+1+(i&1));
		for(int i=0;i<n;i++)
		printf("%d ",2*i+2-(i&1));
	}else puts("NO");
}