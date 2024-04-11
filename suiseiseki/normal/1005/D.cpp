#include <cstdio>
char s[200005];
int nxt[5];
int f[200005];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int len=0;
	scanf("%s",s+1);
	while(s[++len]!='\0');
	len--;
	nxt[0]=nxt[1]=nxt[2]=-1;
	nxt[(s[1]-'0')%3]=1;
	int sum=s[1]-'0';
	sum%=3;
	if(sum==0){
		f[1]=1;
	}
	for(int i=2;i<=len;i++){
		f[i]=f[i-1];
		sum+=s[i]-'0';
		sum%=3;
		if(sum==0){
			f[i]=mx(f[i],1);
		}
		if(nxt[sum]!=-1){
			f[i]=mx(f[i],f[nxt[sum]]+1);
		}
		nxt[sum]=i;
	}
	printf("%d\n",f[len]);
	return 0;
}