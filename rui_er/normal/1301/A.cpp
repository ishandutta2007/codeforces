//vp
#include<bits/stdc++.h>
#define HohleFeuerwerke using namespace std
HohleFeuerwerke;
int n;
bool check(string a,string b,string c)
{
	for(int i=0;i<a.size();i++)
		if(a[i]!=c[i] and b[i]!=c[i]) return false;
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a,b,c;
		cin>>a>>b>>c;
		if(check(a,b,c)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}