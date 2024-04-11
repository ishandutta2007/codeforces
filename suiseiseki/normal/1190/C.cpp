#include <cstdio>
#define Maxn 100000
char s[Maxn+5];
int n,k;
bool l[Maxn+5],r[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if(k>=n-1){
		puts("tokitsukaze");
		return 0;
	}
	l[1]=1;
	for(int i=2;i<=n;i++){
		if(l[i-1]&&s[i]==s[1]){
			l[i]=1;
		}
	}
	r[n]=1;
	for(int i=n-1;i>0;i--){
		if(r[i+1]&&s[i]==s[n]){
			r[i]=1;
		}
	}
	if(l[n-k]||r[k+1]){
		puts("tokitsukaze");
		return 0;
	}
	for(int i=2;i<=n-k;i++){
		if(l[i-1]&&r[i+k]&&s[1]==s[n]){
			puts("tokitsukaze");
			return 0;
		}
	}
	if(2*k<n||k==1){
		puts("once again");
		return 0;
	}
	for(int i=2;i<=n-k;i++){
		if(!l[i-1]||!r[i+k]){
			puts("once again");
			return 0;
		}
	}
	puts("quailty");
	return 0;
}