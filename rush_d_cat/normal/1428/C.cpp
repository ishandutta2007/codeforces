#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
char s[N];
char stk[N];int top=0;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		top=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='A'){
				stk[++top] = 'A';
			}else{
				if(top==0) stk[++top] = 'B';
				else --top;
			}
		}
		printf("%d\n", top);
	}
}