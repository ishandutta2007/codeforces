#include <cstdio>
#define Maxn 1000000
int n,a[Maxn+5],cnt[1<<21|5],lst[1<<21|5];
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
void add(int x,int id){
	if(cnt[x]==2||lst[x]==id){
		return;
	}
	cnt[x]++;
	lst[x]=id;
	for(int i=20;i>=0;i--){
		if(x&(1<<i)){
			add(x^(1<<i),id);
		}
	}
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	int ans=0,x,s;
	for(int i=n-1;i>0;i--){
		if(i<n){
			add(a[i+1],i+1);
		}
		if(i==n-1){
			continue;
		}
		x=((1<<21)-1)^a[i];
		s=0;
		for(int j=20;j>=0;j--){
			if(x&(1<<j)){
				if(cnt[s|(1<<j)]>1){
					s|=(1<<j);
				}
			}
		}
		ans=mx(ans,a[i]|s);
	}
	printf("%d\n",ans);
	return 0;
}