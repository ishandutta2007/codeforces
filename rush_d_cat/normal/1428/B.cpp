#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t,n; char s[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s);
		int f=0;
		for(int i=0;i<n;i++){
			if(s[i]=='<')f|=1;
			if(s[i]=='>')f|=2;
		}
		if(f!=3){
			printf("%d\n", n);
		}else{
			int ans=0;
			for(int i=0;i<n;i++){
				if(s[i]=='-' || s[(i-1+n)%n]=='-') ans++;
			}
			printf("%d\n", ans);
		}
	}
}