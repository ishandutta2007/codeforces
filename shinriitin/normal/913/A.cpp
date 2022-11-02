#include <bits/stdc++.h>

template<typename T>inline void read(T&x){
	register int f,c; f=1; 
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	for(x=c-48;isdigit(c=getchar());x=x*10+c-48);
	x*=f;
}

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	if(n>=30)printf("%d\n",m);
	else printf("%d\n",m%(1<<n));
	return 0;
}