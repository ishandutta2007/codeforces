# include <bits/stdc++.h>
# define rr register
const int N=200010,INF=0x3f3f3f3f;
int a[N];
int n;
inline int read(void){
	int res,f=1;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-')f=-1;
	res=c-48;
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-48;
	return res*f;
}
int main(void){
	int T=read();
	while(T--){
		n=read();
		for(rr int i=1;i<=n;++i){
			a[i]=read();
		}
		int l=-1,r=-1;
		for(rr int i=1;i<=n;++i){
			if(a[i]==i){
				continue;
			}else{
				l=i;
				break;
			}
		}
		for(rr int i=n;i>=1;--i){
			if(a[i]==i){
				continue;
			}else{
				r=i;
				break;
			}
		}
		bool flag=true;
		for(rr int i=l;i<=r;++i){
			if(a[i]==i){
				flag=false;
				break;
			}
		}
		if(l==-1&&r==-1){
			puts("0");
		}else{
			if(flag){
				puts("1");
			}else{
				puts("2");
			}
		}
	}	
	return 0;
}