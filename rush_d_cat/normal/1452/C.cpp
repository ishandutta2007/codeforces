#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
char s[N];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%s",s+1);
		int A=0,B=0,ans=0;

		for(int i=1;s[i];i++){
			if(s[i]=='('){
				A++;
			}else if(s[i]==')'){
				if(A>0){
					--A; ans++;
				}
			}else if(s[i]=='['){
				B++;
			}else if(s[i]==']'){
				if(B>0) {
					--B; ans++;
				}
			}
		}
    	printf("%d\n", ans);
    } 
}