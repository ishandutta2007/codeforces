#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3030;
const int p = 998244353;

ll n,m,f[N][N],ans,z[N];
char c[N],s[N];


int main()
{
	scanf("%s",c+1);
	scanf("%s",s+1);
	n = strlen(c+1) , m = strlen(s+1);
	z[0] = 1;
	for(int i=1;i <= n;i++) z[i] = (z[i-1] << 1)%p;
	for(int i=0;i <= m;i++){
		f[i+1][i] = 2;
		if(c[1] == s[i]) f[i][i] = 2;
	}
	ans = (ans+f[1][m])%p; //!!!
	for(int i=2;i <= n;i++){
		for(int j=1;j <= m;j++){
			if(c[i] == s[j])
				f[j][m] = (f[j][m]+f[j+1][m])%p;
		}
		for(int j=0;j+i-1 < m;j++){
			if(c[i] == s[j])
				f[j][j+i-1] = (f[j][j+i-1]+f[j+1][j+i-1])%p;
			if(c[i] == s[j+i])
				f[j+1][j+i] = (f[j+1][j+i]+f[j+1][j+i-1])%p;
		}
		ans = (ans+f[1][m])%p;
		f[m+1][m] = z[i];
	}
	printf("%lld\n",ans);
}