#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int main()
{
	cin>>str;
	int cnt=0;
	bool f=false;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]<='a'+cnt)
		{
			str[i]='a'+cnt;
			cnt++;
		}
		if(cnt==26)
		{
			f=true;
			break;
		}
	}
	if(!f) puts("-1"); else cout<<str<<endl;
	return 0;
}