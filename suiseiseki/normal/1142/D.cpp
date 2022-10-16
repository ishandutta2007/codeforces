#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
int n;
ll f[Maxn+5][15];
char s[Maxn+5];
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	ll ans=0;
	for(int i=1;i<=n;i++){
		int x=s[i]-'0';
		if(x){
			f[i][x]++;
		}
		for(int j=1;j<=10;j++){
			if(x<j){
				f[i][(j*(j-1)/2+x+10)%11]+=f[i-1][j];
			}
		}
		for(int j=0;j<=10;j++){
			ans+=f[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}