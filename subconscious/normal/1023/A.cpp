#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5,P=1e9+7;
char s[N],t[N];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	rep(i,n)if(s[i]=='*'){
		rep(j,i-1)if(s[j]!=t[j]){puts("NO");return 0;}
		rep(j,n-i)if(s[n-j+1]!=t[m-j+1]){puts("NO");return 0;}
		if(n-1>m){puts("NO");return 0;}
		puts("YES");
		return 0;
	}
	if(n!=m){puts("NO");return 0;}
	rep(i,n)if(s[i]!=t[i]){puts("NO");return 0;}
	puts("YES");
}