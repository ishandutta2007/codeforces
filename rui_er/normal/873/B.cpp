//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;

int n;
string s;
int k, ans;
int bin[2*MAXN+2];

int main()
{
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		s[i-1] - '0' ? ++k : --k;
		if(!k) ans = max(ans, i);
		if(bin[MAXN+k]) ans = max(ans, i-bin[MAXN+k]);
		else bin[MAXN+k] = i;
	}
	cout<<ans<<endl;
	return 0;
}