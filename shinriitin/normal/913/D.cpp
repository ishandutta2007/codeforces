#include <bits/stdc++.h>

template<typename T>inline void read(T&x){
	register int f,c; f=1; 
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	for(x=c-48;isdigit(c=getchar());x=x*10+c-48);
	x*=f;
}

const int max_N = 2e5 + 21;

int n,T,max_T;

int a[max_N],t[max_N];

int cnt[max_N+21];

inline bool check(int x){
	for(int i=1;i<=max_T;++i)cnt[i]=0;
	if(x>n)return 0;
	for(int i=1;i<=n;++i)
		if(a[i]>=x){
			++cnt[t[i]];
		}
	int res=0,sum=0;
	for(int i=1;i<=max_T;++i)
		while(cnt[i]){
			if((sum+=i)>T){
				return res>=x;
			}
			++res,--cnt[i];
		}
	return res>=x;
}

int tmp[max_N],tot;

inline void display(int x){
	if(!x){
		puts("");
		return;
	}
	for(int i=1;i<=n;++i)
		if(a[i]>=x){
			tmp[++tot]=i;
		}
	std::sort(tmp+1,tmp+1+tot,[&](int x,int y){return t[x]<t[y];});
	for(int i=1;i<=x;++i){
		printf("%d%c",tmp[i]," \n"[i==x]);
	}
}

int main(){
	read(n),read(T);
	for(int i=1;i<=n;++i){
		read(a[i]),read(t[i]);
		max_T=std::max(max_T,t[i]);
	}
	int l=1,r=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	printf("%d\n%d\n",l-1,l-1);
	display(l-1);
	return 0;
}