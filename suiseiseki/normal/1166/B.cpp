#include <cstdio>
const char mp[10][10]={{"aeiou"},
					   {"eioua"},
					   {"iouae"},
					   {"ouaei"},
					   {"uaeio"}};
int main(){
	int k;
	scanf("%d",&k);
	int n,m;
	for(n=5;n<=k;n++){
		if(k%n==0){
			m=k/n;
			break;
		}
	}
	if(m<5){
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			putchar(mp[i%5][j%5]);
		}
	}
	puts("");
	return 0;
}