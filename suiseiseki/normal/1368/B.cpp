#include <cstdio>
typedef long long ll;
ll k;
int num[15];
const char op_s[15]={"0codeforces"};
int main(){
	scanf("%lld",&k);
	for(int i=1;i<=10;i++){
		num[i]=1;
	}
	ll cur_val=1;
	int pos=1;
	while(cur_val<k){
		cur_val=cur_val/num[pos]*(num[pos]+1);
		num[pos]++;
		pos=pos%10+1;
	}
	for(int i=1;i<=10;i++){
		while(num[i]--){
			putchar(op_s[i]);
		}
	}
	putchar('\n');
	return 0;
}