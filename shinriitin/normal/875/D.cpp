#include <bits/stdc++.h>

template<class T>inline void read(T&x){
	register int c; while(c=getchar(),c<48||c>57);
	for(x=0;c>47&&c<58;c=getchar())x=x*10+c-48;	
}

typedef long long ll;

const int max_N=2e5;

int n,a[max_N+21];

int tmp[40],st[max_N+21],top;

int L[max_N+21],R[max_N+21],L1[max_N+21],R1[max_N+21];

ll ans;

int main(){
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i]);
		for(int j=0;j<=30;++j)
			if((a[i]>>j)&1){
				tmp[j]=i;
			}
			else{
				L1[i]=std::max(L1[i],tmp[j]);	
			}
		while(top&&a[st[top]]<a[i])--top;
		L[i]=st[top]+1;
		st[++top]=i;
	}
	st[top=0]=n+1;
	for(int i=0;i<=30;++i)tmp[i]=n+1;
	for(int i=n;i;--i){
		R1[i]=n+1;
		for(int j=0;j<=30;++j)
			if((a[i]>>j)&1){
				tmp[j]=i;
			}
			else{
				R1[i]=std::min(R1[i],tmp[j]);	
			}
		while(top&&a[st[top]]<=a[i])--top;
		R[i]=st[top]-1;
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		int l=L[i]<=L1[i]?L1[i]-L[i]+1:0;
		int r=R[i]>=R1[i]?R[i]-R1[i]+1:0;
		ans+=1ll*l*(R[i]-i+1)+1ll*(i-L[i]+1)*r-1ll*l*r;
	}
	printf("%I64d\n",ans);
	return 0;	
}