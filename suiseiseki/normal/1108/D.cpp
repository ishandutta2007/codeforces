#include <cstdio>
#define Maxn 200000
char s[Maxn+5];
int a[Maxn+5];
int n;
char d_1[3]={'R','G','B'};
int d_2[500];
int main(){
	d_2['R']=0;
	d_2['G']=1;
	d_2['B']=2;
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		a[i]=d_2[s[i]];
	}
	a[n+1]=4;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			a[i]++;
			a[i]%=3;
			if(a[i]==a[i+1]){
				a[i]++;
				a[i]%=3;
			}
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		putchar(d_1[a[i]]);
	}
	puts("");
	return 0;
}