#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 300000
#define ll long long
char s[Maxn+5];
int n;
bool check(int left,int right){
	for(int i=left;i<=right;i++){
		for(int j=1;i+(j<<1)<=right;j++){
			if(s[i]==s[i+j]&&s[i]==s[i+(j<<1)]){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	ll ans=0;
	for(int i=3;i<=n;i++){
		for(int j=i-2;j>0;j--){
			if(check(j,i)){
				ans+=j;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}