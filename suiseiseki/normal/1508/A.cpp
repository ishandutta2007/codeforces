#include <cstdio>
const int Maxn=100000;
char s[3][Maxn<<1|5];
int n;
int val[3];
void solve(){
	scanf("%d",&n);
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	scanf("%s",s[2]+1);
	for(int i=0;i<3;i++){
		int num_0=0,num_1=0;
		for(int j=1;j<=(n<<1);j++){
			if(s[i][j]=='0'){
				num_0++;
			}
			else{
				num_1++;
			}
		}
		if(num_0>num_1){
			val[i]=0;
		}
		else{
			val[i]=1;
		}
	}
	int t_0,t_1;
	if(val[0]==val[1]){
		t_0=0,t_1=1;
	}
	else if(val[0]==val[2]){
		t_0=0,t_1=2;
	}
	else{
		t_0=1,t_1=2;
	}
	for(int i=1,j=1;i<=(n<<1)||j<=(n<<1);){
		if((i<=(n<<1))&&(s[t_0][i]-'0'!=val[t_0])){
			putchar(s[t_0][i]);
			i++;
		}
		else if((j<=(n<<1))&&(s[t_1][j]-'0'!=val[t_1])){
			putchar(s[t_1][j]);
			j++;
		}
		else{
			putchar((char)(val[t_0]+'0'));
			i++,j++;
		}
	}
	putchar('\n');
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}