#include<bits/stdc++.h>
#define MAXN 70005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
map<string,int> mymap;
set<string> S;
string str[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		S.clear();
		for(int j=1;j<=9;j++)
			for(int k=0;k+j<=9;k++)
				S.insert(str[i].substr(k,j));
		for(auto x:S) mymap[x]++;
	}
	for(int i=0;i<n;i++)
	{
		bool f=false;
		for(int j=1;j<=9;j++)
		{
			for(int k=0;k+j<=9;k++)
			{
				if (mymap[str[i].substr(k,j)]==1)
				{
					cout<<str[i].substr(k,j)<<endl;
					f=true;
					break;
				}
			}
			if(f) break;
		}
	}
	return 0;
}