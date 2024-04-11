#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		string s;
		int n,i,j;
		cin>>n>>s;
		if (n==1||s[0]<=s[1]) {cout<<s[0]<<s[0]<<'\n';continue;}
		for (i=0;i<n-1;i++) if (s[i]<s[i+1]) break;
		/*if (i==n-1||s[i]<s[i+1])
		{
			for (j=0;j<=i;j++) cout<<s[j];
			for (j=i;j>=0;j--) cout<<s[j];
			cout<<'\n';continue;
		}
		j=i;
		while (j<n&&s[j]==s[i]) ++j;
		if (j<n&&s[j]<s[i])*/
		s=s.substr(0,i+1);
		cout<<s;reverse(all(s));cout<<s<<'\n';
	}
}
//5 4 3 2 1 1 2 3 4 4