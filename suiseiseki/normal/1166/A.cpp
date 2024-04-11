#include <cstdio>
#define Maxn 100
int n;
char name[25];
int num[30];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",name);
		num[(*name)-'a']++;
	}
	int ans=0;
	int now;
	for(int i=0;i<26;i++){
		if(num[i]&1){
			now=(num[i]+1)>>1;
			ans+=now*(now-1)>>1;
			now=num[i]>>1;
			ans+=now*(now-1)>>1;
		}
		else{
			now=num[i]>>1;
			ans+=now*(now-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}