#include<bits/stdc++.h>
using namespace std;
const int MX=24;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	vector<int> f(1<<MX);
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		s.resize(unique(s.begin(),s.end())-s.begin());
		for(int a=0;a<(int)s.size();a++)
		{
			f[1<<(s[a]-'a')]++;
			for(int b=a+1;b<(int)s.size();b++)
			{
				f[1<<(s[a]-'a')|1<<(s[b]-'a')]--;
				for(int c=b+1;c<(int)s.size();c++)
				{
					f[1<<(s[a]-'a')|1<<(s[b]-'a')|1<<(s[c]-'a')]++;
				}
			}
		}
	}
	for(int i=1;i<(1<<MX);i<<=1)
	{
		for(int j=0;j<(1<<MX);j+=i<<1)
		{
			for(int k=0;k<i;k++)
			{
				f[i+j+k]+=f[j+k];
			}
		}
	}
	long long ans=0;
	for(int i=0;i<(1<<MX);i++)
	{
		ans^=1ll*f[i]*f[i];
	}
	cout<<ans<<endl;
	return 0;
}