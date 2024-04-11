#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define PB push_back
int main()
{
	set<string> SET;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(SET.empty()||SET.count(s)==0)
		{
		cout<<"NO"<<endl;
		SET.insert(s);
		}
		else
		cout<<"YES"<<endl;
	}
}