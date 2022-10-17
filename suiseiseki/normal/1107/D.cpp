#include <cstdio>
#define Maxn 5200
int mp[Maxn+5][Maxn+5];
int n;
char s[Maxn+5];
int d[205];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<10;i++){
		d[i+'0']=i;
	}
	for(int i=0;i<6;i++){
		d[i+'A']=10+i;
	}
	int now;
	int len;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		len=0;
		while(s[++len]!='\0');
		len--;
		for(int j=1;j<=(n>>2);j++){
			if(j<=(n>>2)-len){
				now=0;
			}
			else{
				now=d[s[j-((n>>2)-len)]];
			}
			for(int k=(j<<2);k>((j-1)<<2);k--){
				mp[i][k]=(now&1);
				now>>=1;
			}
		}
	}
	int ans=n;
	for(int i=1;i<=n;i++){
		now=1;
		for(int j=2;j<=n;j++){
			if(mp[i][j]!=mp[i][j-1]){
				ans=gcd(ans,now);
				now=0;
			}
			now++;
		}
		ans=gcd(ans,now);
	}
	for(int j=1;j<=n;j++){
		now=1;
		for(int i=2;i<=n;i++){
			if(mp[i][j]!=mp[i-1][j]){
				ans=gcd(ans,now);
				now=0;
			}
			now++;
		}
		ans=gcd(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}