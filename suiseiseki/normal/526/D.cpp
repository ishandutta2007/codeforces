#include <cstdio>
#define Mod 10837457
char s[1000005];
int f[1000005];
int p[1000005];
void init();
int hash(char *s,int len);
int geth(char *s,int left,int right);
bool check(int x,int len);
int main(){
	init();
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	int left,right,mid;
	left=1,right=n;
	while(left<right){
		mid=(left+right)>>1;
		if(check(mid,n)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	for(int i=1,j;i<n;i++){
		j=f[i];
		while(j&&s[i]!=s[j]){
			j=f[j];
		}
		if(s[i]==s[j]){
			f[i+1]=j+1;
		}
	}
	int tmp;
	for(int i=0;i<n;i++){
		tmp=(i+1)/(i+1-f[i+1]);
		if(tmp/k+((i+1)%(i+1-f[i+1])==0)>tmp%k){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	puts("");
	return 0;
}
void init(){
	p[0]=1;
	for(int i=1;i<=1000000;i++){
		p[i]=(int)((long long)p[i-1]*29ll%Mod);
	}
}
int hash(char *s,int len){
	int ans=0;
	for(int i=1;i<=len;i++){
		ans=((ans*29ll)+(s[i]-'a'+1))%Mod;
	}
	return ans;
}
int geth(char *s,int left,int right){
	int ans=0;
	for(int i=left;i<=right;i++){
		ans=(int)((ans*29ll)+(s[i]-'a'+1))%Mod;
	}
	return ans;
}
bool check(int x,int len){
	for(int i=1;i<=len;i++){
		if(s[i]==s[len]){
			return 0;
		}
	}
	return 1;
}