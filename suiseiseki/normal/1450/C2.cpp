#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int min_3(int a,int b,int c){
	return min(min(a,b),c);
}
int min_6(int a,int b,int c,int d,int e,int f){
	return min(min_3(a,b,c),min_3(d,e,f));
}
const int Maxn=300;
int n;
char s[Maxn+5][Maxn+5];
int work(int x,int y,bool flag){
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i+j)%3==x&&s[i][j]=='O'){
				ans++;
			}
			if((i+j)%3==y&&s[i][j]=='X'){
				ans++;
			}
		}
	}
	if(flag){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((i+j)%3==x&&s[i][j]=='O'){
					putchar('X');
				}
				else if((i+j)%3==y&&s[i][j]=='X'){
					putchar('O');
				}
				else{
					putchar(s[i][j]);
				}
			}
			putchar('\n');
		}
	}
	return ans;
}
void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	int num_0=work(0,1,0),num_1=work(0,2,0),num_2=work(1,2,0),num_3=work(1,0,0),num_4=work(2,0,0),num_5=work(2,1,0);
	int minn=min_6(num_0,num_1,num_2,num_3,num_4,num_5);
	if(num_0==minn){
		work(0,1,1);
	}
	else if(num_1==minn){
		work(0,2,1);
	}
	else if(num_2==minn){
		work(1,2,1);
	}
	else if(num_3==minn){
		work(1,0,1);
	}
	else if(num_4==minn){
		work(2,0,1);
	}
	else{
		work(2,1,1);
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