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
	int n=str.size();
	while(str[n-1]=='0') n--;
	bool f=true;
	int l=0,r=n-1;
	while(r>=l)
	{
		if(str[l]!=str[r]) {f=false; break;}
		l++;
		r--;
	}
	if(f) puts("YES"); else puts("NO");
	return 0;
}