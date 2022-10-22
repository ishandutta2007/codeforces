#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);c=getchar();
	}
	return x;
}
int T;
int n,k;
int a[100010];
bool check(int x){
	int tmp=0;
	for(int i=1;i<=n;++i) if(a[i]*2<x) tmp++;
	bool f1=0,f2=0;
	for(int i=1;i<=n;++i) if(a[i]*2<x||a[i]>=x) f1=1;
	for(int i=1;i<n;++i) if((a[i]*2<x||a[i]>=x)&&(a[i+1]*2<x||a[i+1]>=x)) f2=1;
	if(!f2) ++tmp;if(!f1) ++tmp;
	return tmp<=k;
}
int main(){
    // freopen("D.out","w",stdout);
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i) a[i]=read();
		if(n==2){
			if(k==0) printf("%d\n",min(a[1],a[2]));else if(k==1) printf("%d\n",max(a[1],a[2]));else printf("1000000000\n");continue ;
		}
		int l=0,r=1e9,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)){
				ans=mid,l=mid+1;
			}
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}