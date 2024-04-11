#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
int ask(const string &s) {cout<<"? "<<s<<endl;int r;cin>>r;return r;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,r=0;
	cin>>n>>m;
	string s(m,'0');
	vector<pair<int,int>> v(m);
	vector<int> sum(m+1);
	for (i=0;i<m;i++)
	{
		s[i]='1';
		v[i]={ask(s),i};
		s[i]='0';
	}
	sort(all(v));
	for (i=0;i<m;i++)
	{
		s[v[i].second]='1';
		sum[i+1]=ask(s);
	}
	for (i=0;i<m;i++) r+=(sum[i+1]==sum[i]+v[i].first)*v[i].first;
	cout<<"! "<<r<<endl;
}