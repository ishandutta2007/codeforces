#include <cstdio>
int d[1005],vis[1005];
int main(){
    int flag=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	scanf("%d",&d[i]);
        vis[d[i]]++;
    }
    int ans=0;
    for(int i=1;i<=100;i++){
        if(vis[i]==1){
        	ans++;
		}
        if(vis[i]>=3){
        	flag=1;
		}
    }
	if(!(ans&1)){
		puts("YES");
		int g=0;
		for(int i=0;i<n;i++){
			if(vis[d[i]]==1&&g){
				putchar('A');
			}
			else{
				putchar('B');
			}
			if(vis[d[i]]==1){
				g^=1;
			}
		}
		puts("");
		return 0;
	}
	if(flag==0){
		puts("NO");
		return 0;
	}
	puts("YES");
	int cnt=0,f=0;
	for(int i=0;i<n;i++){
		if(cnt<(ans>>1)&&vis[d[i]]==1){
			putchar('B');
			cnt++;
		}
		else if(vis[d[i]]>=3&&f==0){
			putchar('B');
			f=1;
		}
		else{
			putchar('A');
		}
	}
	puts("");
    return 0;
}