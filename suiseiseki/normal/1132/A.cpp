#include <cstdio>
int cnt[4];
int main(){
	for(int i=0;i<4;i++){
		scanf("%d",&cnt[i]);
	}
	if(cnt[0]!=cnt[3]){
		puts("0");
		return 0;
	}
	if(cnt[2]>0&&cnt[0]==0){
		puts("0");
		return 0;
	}
	puts("1");
	return 0;
}