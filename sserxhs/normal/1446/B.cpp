#include <bits/stdc++.h>
using namespace std;
const int N=5e3+2;
string S,T;
char a[N],b[N];
int f[N][N];
int n,m;
int main()
{
	int i,j;
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>S>>T;
	for (i=1;i<=n;i++) a[i]=S[i-1];
	for (i=1;i<=m;i++) b[i]=T[i-1];
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) f[i][j]=max({f[i-1][j]-1,f[i][j-1]-1,f[i-1][j-1]-2+4*(a[i]==b[j]),0});
	int ans=0;
	for (i=1;i<=n;i++) ans=max(ans,*max_element(f[i]+1,f[i]+m+1));
	cout<<ans<<endl;
}