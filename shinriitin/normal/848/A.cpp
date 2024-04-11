#include <bits/stdc++.h>

template<class Q>inline void read(Q&x){
	register int f,c;
	f=1;
	while(c=getchar(),c<48||c>57)if(c=='-')f=-1;
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;
	x*=f;
}

int k;

int main(){
	read(k);
	if(!k){
		puts("a");
		return 0;	
	}
	for(int i=0;i<26;++i){
		if(!k)break;
		int l=1,r=100000;
		while(l<r){
			int mid=(l+r)>>1;
			if(1ll*mid*(mid-1)/2>k)r=mid;
			else l=mid+1;
		}
		int ans=l-1;
		k-=ans*(ans-1)/2;
		while(ans--)putchar('a'+i);
	}
	puts("");
	return 0;
}