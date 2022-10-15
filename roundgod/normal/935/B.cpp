#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,side;
string str;
P pos;
int main()
{
	scanf("%d",&n);
	cin>>str;
	int cnt=0;
	pos.F=pos.S=0;
	if(str[0]=='U') pos.S=1; else pos.F=1; 
	int side=str[0]=='U'?1:0;
	for(int i=1;i<n;i++)
	{
		if(str[i]=='U') pos.S++; else pos.F++;
		if(pos.F>pos.S&&side==1)
		{
			side=0;
			cnt++;
		}
		if(pos.S>pos.F&&side==0)
		{
			side=1;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}