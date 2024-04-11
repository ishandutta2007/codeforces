#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 1000000
#define ll long long
char s[Maxn+5];
int n;
int f[Maxn+5],g[Maxn+5];
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		if(s[i]=='o'){
			f[i]=f[i-1];
			continue;
		}
		while(j<=n&&s[j]==s[i]){
			j++;
		}
		j--;
		f[j]=f[i-1]+(j-i);
	}
	for(int i=n,j;i>0;i=j-1){
		j=i;
		if(s[i]=='o'){
			g[i]=g[i+1];
			continue;
		}
		while(j>0&&s[j]==s[i]){
			j--;
		}
		j++;
		g[j]=g[i+1]+(i-j);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='o'){
			ans+=1ll*f[i]*g[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}