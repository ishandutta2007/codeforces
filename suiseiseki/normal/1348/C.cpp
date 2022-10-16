#include <cstdio>
const int Maxn=100000;
char s[Maxn+5];
int n,k;
int num[26];
int sz[26];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(int i=0;i<26;i++){
			num[i]=0;
			sz[i]=0;
		}
		for(int i=1;i<=n;i++){
			num[s[i]-'a']++;
		}
		int min_num=26;
		for(int i=0;i<26;i++){
			if(num[i]){
				min_num=i;
				break;
			}
		}
		int all_num=0;
		for(int i=0;i<26;i++){
			if(num[i]){
				all_num++;
			}
		}
		if(num[min_num]>=k){
			if(all_num==1){
				int now=(num[min_num]+k-1)/k;
				while(now--){
					printf("%c",(char)(min_num+'a'));
				}
				puts("");
				continue;
			}
			if(all_num==2&&num[min_num]==k){
				for(int i=min_num+1;i<26;i++){
					if(num[i]){
						int now=(num[i]+k-1)/k;
						printf("%c",(char)(min_num+'a'));
						while(now--){
							printf("%c",(char)(i+'a'));
						}
					}
				}
				puts("");
				continue;
			}
			num[min_num]-=k-1;
			for(int i=0;i<26;i++){
				while(num[i]--){
					printf("%c",(char)(i+'a'));
				}
			}
			puts("");
		}
		else{
			bool flag=1;
			while(flag){
				k-=num[min_num];
				for(int i=min_num+1;i<26;i++){
					if(num[i]){
						min_num=i;
						if(num[i]>=k){
							printf("%c",(char)(i+'a'));
							flag=0;
						}
						break;
					}
				}
			}
			puts("");
		}
	}
	return 0;
}