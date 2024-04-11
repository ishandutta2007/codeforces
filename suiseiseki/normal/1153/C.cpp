#include <cstdio>
#define Maxn 300000
char s[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n&1){
		puts(":(");
		return 0;
	}
	if(s[n]=='?'){
		s[n]=')';
	}
	if(s[1]=='?'){
		s[1]='(';
	}
	if(s[1]==')'||s[n]=='('){
		puts(":(");
		return 0;
	}
	int sum=0;
	int total=0;
	for(int i=2;i<n;i++){
		if(s[i]==')'){
			total++;
		}
	}
	for(int i=n-1;i>1;i--){
		if(s[i]=='?'){
			if(total<((n-2)>>1)){
				total++;
				s[i]=')';
				sum++;
			}
			else{
				s[i]='(';
				sum--;
			}
		}
		else{
			if(s[i]==')'){
				sum++;
			}
			else{
				sum--;
				if(sum<0){
					puts(":(");
					return 0;
				}
			}
		}
	}
	sum=0;
	for(int i=2;i<n;i++){
		if(s[i]==')'){
			sum--;
		}
		else{
			sum++;
		}
		if(sum<0){
			puts(":(");
			return 0;
		}
	}
	puts(s+1);
	return 0;
}