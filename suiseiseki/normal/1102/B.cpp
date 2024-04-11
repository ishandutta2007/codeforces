#include <cstdio>
#define Maxn 5000
int a[Maxn+5],c[Maxn+5];
int num[Maxn+5];
int col[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int max_c=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
		c[i]=num[a[i]];
		max_c=mx(max_c,num[a[i]]);
		col[c[i]]++;
		if(c[i]>k){
			puts("NO");
			return 0;
		}
	}
	if(max_c<k){
		for(int i=1;max_c<k;i++){
			if(col[c[i]]>1){
				col[c[i]]--;
				max_c++;
				c[i]=max_c;
				col[max_c]++;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d ",c[i]);
	}
	puts("");
	return 0;
}
/////