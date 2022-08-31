#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MX 1000002

typedef long long LL;

int gr[MX], lesser[MX];
int B[MX];
pair<int,int> A[MX];
int tree[MX];

void U(int x,int v){for(;x<MX;x+=x&-x) tree[x]+=v; }
int Q(int x){ int r=0; for(;x;x-=x&-x)r+=tree[x]; return r; }

int main()
{
	int n; scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		A[i] = make_pair(x,i);
	}

	sort(A,A+n);

	for(int i=0;i<n;i++)
	{
		B[A[i].second] = i+1;
	}

	for(int i=0;i<n;i++)
	{
		gr[i] = i - Q(B[i]);
		U(B[i],1);
	}

	memset(tree,0,sizeof tree);
	for(int i=n-1;i>=0;i--)
	{
		lesser[i] = Q(B[i]);
		U(B[i],1);
	}

	LL r = 0;
	for(int i=0;i<n;i++) r+=1ll*lesser[i]*gr[i];

	cout<<r<<endl;

	return 0;
}