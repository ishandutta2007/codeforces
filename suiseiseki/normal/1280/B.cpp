#include <cstdio>
#include <algorithm>
const int Maxn=60;
char s[Maxn+5][Maxn+5];
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	int ans=5;
	bool all_flag=1;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			if(s[i][j]=='A'){
				ans=std::min(ans,4);
				if(j==1||j==m||i==1||i==n){
					ans=std::min(ans,3);
				}
				if((i==1&&j==1)||(i==n&&j==m)||(i==1&&j==m)||(i==n&&j==1)){
					ans=std::min(ans,2);
				}
			}
			else{
				all_flag=0;
			}
		}
	}
	if(all_flag){
		ans=std::min(ans,0);
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=m;j++){
			if(s[i][j]=='P'){
				flag=0;
				break;
			}
		}
		if(!flag){
			continue;
		}
		ans=std::min(ans,2);
		if(i==1||i==n){
			ans=std::min(ans,1);
		}
	}
	for(int j=1;j<=m;j++){
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(s[i][j]=='P'){
				flag=0;
				break;
			}
		}
		if(!flag){
			continue;
		}
		ans=std::min(ans,2);
		if(j==1||j==m){
			ans=std::min(ans,1);
		}
	}
	if(ans==5){
		puts("MORTAL");
	}
	else{
		printf("%d\n",ans);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}