#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	int cnt=0;
	for(int i=1;i<n;i++)
		if(str[i]!=str[i-1]) cnt++,i++;
	printf("%d\n",n-cnt);
	return 0;
}