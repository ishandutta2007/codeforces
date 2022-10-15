#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
string ans;
map<string,int> mp;
int main()
{
	scanf("%d",&n);
	cin>>str;
	int res=0;
	for(int i=0;i<n-1;i++)
	{
		string s=str.substr(i,2);
		if(mp.find(s)==mp.end())
		{
			mp[s]=1;
			if(mp[s]>res) {res=mp[s]; ans=s;}
		}
		else
		{
			mp[s]++;
			if(mp[s]>res) {res=mp[s]; ans=s;}
		}
	}
	cout<<ans<<endl;
	return 0;
}