#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n;char s[N];

int a[N],top=0;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1); 
		top=0;
		for(int i=1,j=1;i<=n;i=j){
			while(j<=n && s[i]==s[j])++j;
			a[++top]=j-i;
		}
		int now=1,res=0;
		for(int i=1;i<=top;i++){
			while(now<=top && a[now]==1) ++now;
			++res;
			if(now<=top) {
				a[now]--;
			}else{
				i++;
			}
			if(i==now)++now;
		}
		printf("%d\n", res);
	}
}
/*
110011
*/