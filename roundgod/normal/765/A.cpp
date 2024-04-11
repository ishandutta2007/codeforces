#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
using namespace std;
int n,k,a[MAXN];
string S;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n+1;i++)
		cin>>S;
	if(n&1) puts("contest"); else puts("home");
	return 0;
}