#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int a,t,st[N];
double n;
int main(){
	for(;scanf("%d",&a)==1;)
	st[t++]=a;
	for(;t--;){
		n=st[t];
		n=sqrt(abs(n))+5*n*n*n;
		printf("f(%d) = ",st[t]);
		if(n<400)
		printf("%.2lf\n",n);
		else printf("MAGNA NIMIS!\n");
	}
}