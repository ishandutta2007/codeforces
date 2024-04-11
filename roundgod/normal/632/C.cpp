#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string a[MAXN];
bool cmp(string x,string y)
{
	return x+y<y+x;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	string ans="";
	for(int i=0;i<n;i++)
		ans+=a[i];
	cout<<ans<<endl;
	return 0;
}