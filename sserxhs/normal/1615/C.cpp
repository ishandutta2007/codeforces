#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int r[2];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n,i,j;string s,t;
		r[0]=r[1]=0;
		cin>>n>>s>>t;
		int ans=n+1;
		for (i=0;i<n;i++) if (s[i]!=t[i]) r[s[i]-'0']++;
		if (r[0]==r[1]) ans=min(ans,r[0]+r[1]);
		r[0]=r[1]=0;
		for (i=0;i<n;i++) if (s[i]==t[i]) r[s[i]-'0']++;
		if (r[1]==r[0]+1) ans=min(ans,r[0]+r[1]);
		cout<<(ans==n+1?-1:ans)<<'\n';
	}
}