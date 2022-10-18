#include <bits/stdc++.h>
using namespace std;
const int N=1e5+2;
struct Q
{
	int x,y;
	Q(){}
	Q(int a,int b):x(a),y(b){}
	bool operator<(const Q &o) const {return x<o.x;}
};
Q a[N];
int f[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++) f[i]=f[lower_bound(a+1,a+n+1,Q(a[i].x-a[i].y,0))-a-1]+1;
	cout<<n-*max_element(f+1,f+n+1);
}