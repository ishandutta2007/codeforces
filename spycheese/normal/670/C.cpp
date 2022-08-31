#include <bits/stdc++.h>

using namespace std;

const int maxn=(int)2e5+5;
int n,t,b[maxn],c[maxn],best1,best2,ans,mm;
unordered_map <int,int> m;

int main()
{
    m.rehash(maxn);
	//i changed code. codeforces,test it please
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		m[t]++;
	}
	cin >> mm;
	for(int i=0;i<mm;i++)
		cin >> b[i];
	for(int i=0;i<mm;i++)
		cin >> c[i];
	for(int i=0;i<mm;i++)
	{
		if(m[b[i]]>best1)
		{
			best1=m[b[i]];
			best2=m[c[i]];
			ans=i;
			continue;
		}
		if(m[b[i]]<best1) continue;
		if(m[c[i]]>best2)
		{
			best2=m[c[i]];
			ans=i;
		}
	}
	/*cin >> b >> c;
	best1=m[b];
	best2=m[c];
	for(int i=1;i<mm;i++)
	{
		cin >> b >> c;
		if(m[b]>best1)
		{
			best1=m[b];
			best2=m[c];
			ans=i;
			continue;
		}
		if(m[b]<best1) continue;
		if(m[c]>best2)
		{
			best2=m[c];
			ans=i;
		}
	}*/
	cout << ans+1;
	return 0;
}