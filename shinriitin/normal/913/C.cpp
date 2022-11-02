#include <bits/stdc++.h>

template<typename T>inline void read(T&x){
	register int f,c; f=1; 
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	for(x=c-48;isdigit(c=getchar());x=x*10+c-48);
	x*=f;
}

using ll = long long;

const int max_N = 40;

int n,L,c[max_N];

ll f[max_N];

inline ll calc(int x){
	if(!x)return 0;
	if(x>=(1<<(n-1))){
		return f[n-1]*(x/(1<<(n-1)))+calc(x%(1<<(n-1)));
	}
	int i=0; while((1<<i)<x)++i;
	if((1<<i)==x)return f[i];
	return std::min(f[i],f[i-1]+calc(x-(1<<(i-1))));
}

int main(){
	scanf("%d%d",&n,&L);
	for(int i=0;i<n;++i){
		scanf("%d",c+i);
		f[i]=c[i];
		if(i)f[i]=std::min(f[i],f[i-1]<<1);
	}
	for(int i=n-2;~i;--i)f[i]=std::min(f[i],f[i+1]);
	printf("%I64d\n",calc(L));
	return 0;
}