#include <cstdio>
const int Maxn=200000;
const int Mod=1000000007;
int n;
char s[Maxn+5];
int num[5];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int tmp=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='a'){
			num[0]=(num[0]+tmp)%Mod;
		}
		else if(s[i]=='b'){
			num[1]=(num[1]+num[0])%Mod;
		}
		else if(s[i]=='c'){
			num[2]=(num[2]+num[1])%Mod;
		}
		else{
			num[2]=((num[2]+num[1])%Mod+(num[2]<<1)%Mod)%Mod;
			num[1]=((num[1]+num[0])%Mod+(num[1]<<1)%Mod)%Mod;
			num[0]=((num[0]+tmp)%Mod+(num[0]<<1)%Mod)%Mod;
			tmp=3ll*tmp%Mod;
		}
	}
	printf("%d\n",num[2]);
	return 0;
}
/*
aaaa   0
aaab   0
aaac   0
aaba   0
aabb   0
aabc   2
aaca   0
aacb   0
aacc   0
abaa   0
abab   0
abac   1
abba   0
abbb   0
abbc   2
abca   1
abcb   1
abcc   2
acaa   0
acab   0
acac   0
acba   0
acbb   0
acbc   1
acca   0
accb   0
accc   0
*/