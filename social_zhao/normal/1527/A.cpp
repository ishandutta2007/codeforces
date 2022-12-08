#include<bits/stdc++.h>
using namespace std;

int t,n; 

int main(){
	scanf("%d",&t);
	while(t--)
		scanf("%d",&n),printf("%d\n",(1<<(int)log2(n))-1);
}