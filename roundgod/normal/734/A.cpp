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
int n,cnt1,cnt2;
int main()
{
	scanf("%d",&n);
	cin>>str;
	cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
		if(str[i]=='A') cnt1++; else cnt2++;
	if(cnt1>cnt2) puts("Anton");
	else if(cnt1<cnt2) puts("Danik");
	else puts("Friendship");
	return 0;
}