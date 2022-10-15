#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[MAXN],L[MAXN],R[MAXN];
int t,n,k;
string S;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	cin>>S;
	R[n-1]=n-1;
	for(int i=n-2;i>=0;i--)
		if(S[i]=='0') R[i]=i; else R[i]=R[i+1];
	L[0]=0;
	for(int i=1;i<n;i++)
		if(S[i-1]=='0') L[i]=i; else L[i]=L[i-1];
	bool f=true;
	for(int i=0;i<n;i++)
	{
		if(a[i]-1<L[i]||a[i]-1>R[i])
		{
			f=false;
			break;
		}
	}
	if(f) puts("YES"); else puts("NO");
	return 0;
}