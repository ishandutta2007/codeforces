#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
string S;
int main()
{
	scanf("%d",&n);
	cin>>str;
	int k=0;
	for(int i=0;i<n/2;i++)
	{
		bool f=true;
		for(int j=0;j<=i;j++)
			if(str[j]!=str[j+i+1]) f=false;
		if(f) k=i+1;
	}
	if(k>0) printf("%d\n",n-k+1); else printf("%d\n",n);
	return 0;
}