#include <bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int a[N],b[N];
int n,i;
struct Q
{
	int l,r;
	Q(){}
	Q(int a,int b):l(a),r(b){}
	bool operator<(const Q &o) const {return l<o.l;}
};
Q c[N];
bool ck(int m)
{
	int i,j=0;
	for (i=1;i<=n&&j<m;i++) if (b[i]>=j&&a[i]>=m-j-1) ++j;
	return j>=m;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i]>>b[i];
		int l=1,r=n;
		while (l<r)
		{
			int m=l+r+1>>1;
			if (ck(m)) l=m; else r=m-1;
		}
		cout<<l<<'\n';
	}
}