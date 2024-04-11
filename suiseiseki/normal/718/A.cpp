#include <cstdio>
#include <cstring>
#define Maxn 200000
#define Inf 0x3f3f3f3f
int a[Maxn+5],b[Maxn+5];
int f[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	char c=getchar();
	int len_a=0,len_b=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a[++len_a]=(c^48);
		c=getchar();
	}
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		b[++len_b]=(c^48);
		c=getchar();
	}
	memset(f,0x3f,sizeof f);
	for(int i=len_b;i>0;i--){
		if(b[i]>=5){
			f[i]=1;
		}
		else if(b[i]==4){
			f[i]=f[i+1]+1;
		}
	}
	for(int i=1;i<=len_b;i++){
		if(f[i]<=m){
			b[i-1]++;
			m-=f[i];
			for(int j=i;j<=len_b;j++){
				b[j]=0;
			}
			break;
		}
	}
	while(b[len_b]==0){
		len_b--;
	}
	if(b[0]==1){
		a[len_a]++;
		int i=len_a;
		while(a[i]>9){
			a[i-1]++;
			a[i]=0;
			i--;
		}
	}
	if(a[0]==1){
		putchar('1');
	}
	for(int i=1;i<=len_a;i++){
		printf("%d",a[i]);
	}
	if(len_b==0){
		return 0;
	}
	putchar('.');
	for(int i=1;i<=len_b;i++){
		printf("%d",b[i]);
	}
	puts("");
	return 0;
}