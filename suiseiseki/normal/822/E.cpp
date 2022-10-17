#include <cstdio>
int n,m,k;
char s[500005],t[500005];
struct Simple{
	int ff,pos;
}f[100],now;
int main(){
	scanf("%d%s%d%s%d",&n,s,&m,t,&k);
	for(int i=0;i<=n-1;i++){
		for(int j=k-1;j>=0;j--){
			if(i<f[j].pos){
				continue;
			}
			now.ff=f[j].ff,now.pos=i;
			while(s[now.pos]==t[now.ff]&&now.ff<m){
				now.pos++;
				now.ff++;
			}
			if(now.ff==m){
				puts("YES");
				return 0;
			}
			if(now.ff>f[j+1].ff){
				f[j+1]=now;
			}
		}
	}
	puts("NO");
	return 0;
}