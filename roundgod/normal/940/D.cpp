#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,a[MAXN];
string str;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	cin>>str;
	int cnt=4;
	int minl=-INF,maxl=INF,minr=-INF,maxr=INF;
	for(int i=4;i<n;i++)
	{
		if(cnt<4)
		{
			cnt++;
			continue;
		}
		int mini=min(min(a[i],min(a[i-1],a[i-2])),min(a[i-3],a[i-4]));
		int maxi=max(max(a[i],max(a[i-1],a[i-2])),max(a[i-3],a[i-4]));
		if(str[i]=='0'&&str[i-1]=='0') maxl=min(maxl,maxi);
		if(str[i]=='1'&&str[i-1]=='1') minr=max(minr,mini);
		if(str[i]=='0'&&str[i-1]=='1') {maxr=min(maxr,mini-1); cnt=1;}
		if(str[i]=='1'&&str[i-1]=='0') {minl=max(minl,maxi+1); cnt=1;}
	}
	printf("%d %d\n",minl,maxr);
	return 0;
}