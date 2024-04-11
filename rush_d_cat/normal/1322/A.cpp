#include <bits/stdc++.h>
using namespace std;
const int N=1000000+10;
char s[N]; int n;
int main() {
	scanf("%d%s",&n,s+1);
	int sum=0,ans=0,c=0;
	for(int i=1;i<=n;i++){
		sum+=(s[i]=='('?1:-1);
		if(s[i]=='(')c++;
		if(sum<0||(sum==0&&s[i]=='('))ans++;
	}
	if(c*2!=n)return !printf("-1\n");
	cout<<ans<<endl;
}