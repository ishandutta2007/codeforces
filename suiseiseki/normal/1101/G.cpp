#include <cstdio>
#define Maxn 200000
int n,a[Maxn+5],s[Maxn+5],b[35];
bool work(int x){
    for(int i=30;i>=0;i--){
    	if((x>>i)&1){
            if(!b[i]){
                b[i]=x;
                return 1;
            }
            x^=b[i];
        }
	}
    return 0;
}
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    if(!s[n]){
        puts("-1");
        return 0;
    }
    int ans=0;
    for(int i=n;i;i--){
    	if(work(a[i])){
    		ans++;
		}
	}
	printf("%d\n",ans);
    return 0;
}