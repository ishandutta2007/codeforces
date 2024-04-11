#include <cstdio>
#include <algorithm>
using namespace std;
char s[1005];
int main(){
	int t;
	scanf("%d",&t);
	int len;
	while(t--){
	    len=0;
		scanf("%s",s+1);
		while(s[++len]!='\0');
		len--;
		sort(s+1,s+1+len);
		if(s[1]==s[len]){
			puts("-1");
		}
		else{
			puts(s+1);
		}
	}
	return 0;
}