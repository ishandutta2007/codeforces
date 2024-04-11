#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1<<18;
int rk[N];
struct Q
{
	int x,y,z;
	bool operator<(const Q &o) const {return x==o.x?y<o.y:x<o.x;}
	bool operator==(const Q &o) const {return x==o.x&&y==o.y;}
};
Q b[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k,cnt=-1;
	string s;
	cin>>m>>s;n=1<<m;
	for (i=0;i<n;i++) b[i]={s[i],s[i],i};
	sort(b,b+n);
	for (i=0;i<n;i++) rk[b[i].z]=i&&b[i]==b[i-1]?cnt:++cnt;
	for (k=1;k<=m;k++)
	{
		cnt=-1;
		for (i=0;i<n;i++) b[i]={rk[i],rk[i^1<<k-1],i};
		sort(b,b+n);
		for (i=0;i<n;i++) rk[b[i].z]=i&&b[i]==b[i-1]?cnt:++cnt;
	}
	int a=min_element(rk,rk+n)-rk;
	for (i=0;i<n;i++) cout<<s[i^a];
}