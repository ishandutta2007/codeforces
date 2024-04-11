#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

const int max_N=3e5;

int n,k,f[max_N+21],ans[max_N+21];

int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);	
}

std::pair<int,int>a[max_N+21];

int main(){
	read(n),read(k);
	for(int i=1;i<=n;++i){
		read(a[i].first);
		a[i].second=f[i]=i;
	}
	f[n+1]=n+1;
	std::sort(a+1,a+1+n);
	long long ans1=0;
	for(int i=n;i;--i){
		int index=a[i].second;
		int res=std::max(1,index-k);
		res=find(res);
		ans[index]=res;
		ans1+=1ll*(k+res-index)*a[i].first;
		f[res]=res+1;
	}
	printf("%I64d\n",ans1);
	for(int i=1;i<=n;++i)printf("%d%c",k+ans[i],i==n?'\n':' ');
	return 0;	
}