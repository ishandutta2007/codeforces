#include <cstdio>
char s1[200005],s2[200005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int x1=0;
	for(int i=1;i<=n;i++){
		if(s1[i]=='*'){
			x1=i;
		}
	}
	if(x1==0){
		if(n!=m){
			puts("NO");
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(s1[i]!=s2[i]){
				puts("NO");
				return 0;
			}
		}
		puts("YES");
		return 0;
	}
	else{
		if(m<n-1){
			puts("NO");
			return 0;
		}
		for(int i=1;i<x1;i++){
			if(s1[i]!=s2[i]){
				puts("NO");
				return 0;
			}
		}
		for(int i=n;i>x1;i--){
			if(s1[i]!=s2[i-n+m]){
				puts("NO");
				return 0;
			}
		}
		puts("YES");
	}
	return 0;
}