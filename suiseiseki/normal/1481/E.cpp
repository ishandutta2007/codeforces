#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=500000;
int t,n;
int f[Maxn+5],cnt[Maxn+5],a[Maxn+5];
int l[Maxn+5],r[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!l[a[i]]){
			l[a[i]]=i;
		}
		r[a[i]]=i;
	}
	for(int i=n;i>0;i--){
		cnt[a[i]]++;
		f[i]=f[i+1];
		if(i==l[a[i]]){
			f[i]=max(f[i],cnt[a[i]]+f[r[a[i]]+1]);
		}
		else{
			f[i]=max(f[i],cnt[a[i]]);
		}
	}
	printf("%d\n",n-f[1]);
    return 0;
}