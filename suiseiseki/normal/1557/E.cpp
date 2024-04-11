#include <cstdio>
bool check(){
	char s[10];
	scanf("%s",s);
	return (*s)=='D'&&s[1]=='o'&&s[2]=='n'&&s[3]=='e';
}
void solve(){
	bool flag=0;
	for(int i=1;!flag;i=i%8+1){
		for(int j=1;j<=8;j++){
			printf("%d %d\n",i,(i&1)?j:9-j);
			fflush(stdout);
			if(check()){
				flag=1;
				break;
			}
		}
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