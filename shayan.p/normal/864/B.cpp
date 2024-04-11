#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define PB push_back
bool up(char a)
{
	if(a>='A'&&a<='Z')
	return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	set<char> st;
	int Max=0,SSS;
	for(int i=0;i<n;i++)
	{
		if(up(s[i]))
		{
		SSS=st.size();
		Max=max(Max,SSS);
		st.clear();
		}
		else
		st.insert(s[i]);
	}
	SSS=st.size();
	Max=max(Max,SSS);
	cout<<Max;
}