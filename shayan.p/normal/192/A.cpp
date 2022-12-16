/*#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
bool pal(string &s)
{
	for(ll i=0;i<s.size();i++)
	if(s[i]!=s[s.size()-i-1]) return 0;
	return 1;
}
vector<string> v;
int main()
{
	string s;cin>>s;
	for(ll i=0;i<(1<<s.size());i++)
	{
		string ss="";ll cop=i;
		for(ll j=s.size()-1;j>=0;j--)
		{
		if(cop%2)
		ss=s[j]+ss;
		cop/=2;
		}
		if(pal(ss)) v.PB(ss);
	}
	sort(v.begin(),v.end(),greater<string>());
	cout<<v[0];
}

*/
//a funky number
#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
bool is_funky(ll num,ll l=1,ll r=1e9+1)
{
	if(l>r) return 0;
	ll mid=(l+r)/2;
	ll sum=((mid*mid)+mid)/2;
	if(sum==num) return 1;
	if(sum<num) return is_funky(num,mid+1,r);
	if(sum>num) return is_funky(num,l,mid-1);
}
int main()
{
	ll n;cin>>n;
	for(ll i=1;(i*i+i)/2<n;i++)
		if(is_funky(n-((i*i)+i)/2)) {cout<<"YES";return 0;}
		cout<<"NO";
}