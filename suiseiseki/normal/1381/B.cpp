#include <cstdio>
const int Maxn=2000;
int n;
int a[Maxn<<1|5];
int b[Maxn<<1|5],len;
bool f[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=(n<<1);i++){
			scanf("%d",&a[i]);
		}
		len=0;
		for(int i=1,j;i<=(n<<1);i=j+1){
			j=i;
			while(j<(n<<1)&&a[j+1]<a[i]){
				j++;
			}
			b[++len]=j-i+1;
		}
		for(int i=0;i<=n;i++){
			f[i]=0;
		}
		f[0]=1;
		for(int i=1;i<=len;i++){
			for(int j=n-b[i];j>=0;j--){
				if(f[j]){
					f[j+b[i]]=1;
				}
			}
		}
		if(f[n]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}