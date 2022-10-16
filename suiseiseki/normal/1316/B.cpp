#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int Maxn=5000;
int n,m;
string ans,now;
char s[Maxn+5];
int main(){
	int t;
	scanf("%d",&t);
	int now_ans;
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		ans="";
		now_ans=1;
		for(int i=1;i<=n;i++){
			ans+=s[i];
		}
		for(int i=2;i<=n;i++){
			now="";
			for(int j=i;j<=n;j++){
				now+=s[j];
			}
			if(((i-1)&1)==(n&1)){
				for(int j=1;j<i;j++){
					now+=s[j];
				}
			}
			else{
				for(int j=i-1;j>0;j--){
					now+=s[j];
				}
			}
			if(now<ans){
				ans=now;
				now_ans=i;
			}
		}
		cout<<ans<<endl;
		printf("%d\n",now_ans);
	}
	return 0;
}