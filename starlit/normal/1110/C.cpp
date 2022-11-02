#include<bits/stdc++.h>
using namespace std;
int q,n,l,mp[]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main(){
	scanf("%d",&q);
	for(;q--;){
		scanf("%d",&n);
		for(l=0;1<<l<=n;l++);
		if((1<<l)-1>n)printf("%d\n",(1<<l)-1);
		else printf("%d\n",mp[l]);
	}
}