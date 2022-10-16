#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int now=0;
		while((1<<(now+1))<=n-1) now++;
		vector<int> v;
		for(int i=(1<<now);i<=n-1;i++) v.push_back(i);
		v.push_back((n-1)^(1<<now));
		for(int i=0;i<(1<<now);i++) 
		{
			if(i==((n-1)^(1<<now))) continue;
			v.push_back(i);
		}
		for(auto x:v) printf("%d ",x);
		puts("");
	}
	return 0;
}