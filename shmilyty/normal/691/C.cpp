#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
string s,a,b;
int ans;
int main()
{
	cin>>s;
	auto index=find(all(s),'.');
	a=string(s.begin(),index);
	b=string(index,s.end());
	if(b.size()>0&&b[0]=='.')
		b.erase(b.begin());
	reverse(all(a));
	while(a[a.size()-1]=='0'&&a.size()>0)
		a.pop_back();
	reverse(all(a));
	while(b[b.size()-1]=='0'&&b.size()>0)
		b.pop_back();
	reverse(all(b));
	while(a.size()!=1)
	{
		if(a.size()>1)
		{
			if(b.size()>0||a[a.size()-1]!='0')
				b.push_back(a[a.size()-1]);
			a.pop_back();
			ans++;
		}
		if(a=="")
		{
			if(b[b.size()-1]!='0')
				a.push_back(b[b.size()-1]);
			b.pop_back();
			ans--;
		}
	}	
	reverse(all(b));
	cout<<a;
	if(b.size()>0)
		cout<<"."<<b;
	if(ans!=0)
		cout<<"E"<<ans;
	return 0;
}