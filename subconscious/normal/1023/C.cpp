#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5,P=1e9+7;
int n,k,top;
char s[N];
char ans[N];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,n){
		ans[++top]=s[i];
		if(top>1&&n!=k&&ans[top]==')'&&ans[top-1]=='(')ans[top]=ans[top-1]='\0',top-=2,k+=2;
	}
	ans[top+1]='\0';
	printf("%s\n",ans+1);
}