#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define Mod 1000000007
#define ll long long
char s[Maxn+5];
ll f[Maxn+5];
ll sum[Maxn+5];
int las[Maxn+5];
int g_las[Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%s",s+1);
	int n=0;
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		if(s[i]=='a'){
			f[i]=sum[las[i-1]]+1;
			f[i]%=Mod;
			las[i]=las[i-1];
		}
		else if(s[i]=='b'){
			if(s[i-1]=='a'){
				las[i]=i-1;
			}
			else{
				if(s[i-1]=='b'){
					las[i]=las[i-1];
				}
				else{
					las[i]=g_las[i-1];
				}
			}
		}
		else{
			las[i]=las[i-1];
			if(s[i-1]=='a'){
				g_las[i]=i-1;
			}
			else{
				g_las[i]=mx(g_las[i-1],las[i]);
			}
		}
		sum[i]=sum[i-1]+f[i];
		sum[i]%=Mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=f[i];
		ans%=Mod;
	}
	cout<<ans<<endl;
	return 0;
}