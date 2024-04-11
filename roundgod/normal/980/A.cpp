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
int cnt1,cnt2;
int main()
{
	cin>>str;
	cnt1=cnt2=0;
	for(int i=0;i<str.size();i++)
		if(str[i]=='o') cnt1++; else cnt2++;
	if(cnt1==0||cnt2%cnt1==0) puts("YES"); else puts("NO");
	return 0;
}