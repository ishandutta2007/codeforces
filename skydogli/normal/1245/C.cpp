#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
int T,a,n,c,b;
char ch[100005];
int f[100005];
int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
int main(){
    scanf("%s",ch+1);
    n=strlen(ch+1);
    f[0]=1;
    for(int i=1;i<=n;++i){
    	f[i]=f[i-1];
    	if(ch[i]=='m'||ch[i]=='w'){
    		puts("0");
    		return 0;
		}
		if(ch[i]=='n'&&ch[i-1]=='n')f[i]=(f[i]+f[i-2])%Mod;
		if(ch[i]=='u'&&ch[i-1]=='u')f[i]=(f[i]+f[i-2])%Mod;
	}
	printf("%d",f[n]);
	return 0;
}