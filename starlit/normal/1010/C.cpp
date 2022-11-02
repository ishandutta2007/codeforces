#include<bits/stdc++.h>
using namespace std;
int n,k,c,s;
inline int gcd(int x,int y){
	for(;y;swap(x,y),y=y%x);
	return x;
}
int main(){
	scanf("%d%d",&n,&k),s=k;
	for(;n--&&s>1;){
		scanf("%d",&c);
		s=gcd(s,c%k);
	}
	printf("%d\n",k/s);
	for(int i=0;i<k;i+=s)printf("%d ",i);
}