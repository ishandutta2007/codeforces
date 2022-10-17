#include <cstdio>
#include <string>
using namespace std;
#define Maxn 200000
char s[Maxn+5];
char an[Maxn+5];
int n;
string now;
int work(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]!=now[i%3]){
			ans++;
		}
	}
	return ans;
}
int mn(int a,int b){
	if(a>b){
		for(int i=1;i<=n;i++){
			an[i]=now[i%3];
		}
	}
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=(1<<30);
	now="RGB";
	ans=mn(ans,work());
	now="RBG";
	ans=mn(ans,work());
	now="GRB";
	ans=mn(ans,work());
	now="GBR";
	ans=mn(ans,work());
	now="BGR";
	ans=mn(ans,work());
	now="BRG";
	ans=mn(ans,work());
	printf("%d\n",ans);
	puts(an+1);
	return 0;
}