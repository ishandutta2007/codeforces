#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
using namespace std;
bool used[26];
string str;
int main()
{
	cin>>str;
	bool f=true;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='a') continue;
		bool flag=false;
		for(int j=0;j<i;j++)
			if(str[j]==str[i]-1) {flag=true; break;}
		if(!flag) {f=false; break;}
	}
	if(f) puts("YES"); else puts("NO");
	return 0;
}