#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 18
#define MAXM (1<<18)
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,r[MAXM],tmp[MAXM],v[MAXM];
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	iota(r,r+(1<<n),0);
	sort(r,r+(1<<n),[&](int i,int j){return str[i]<str[j];});
	for(int i=0;i<(1<<n);i++) v[r[i]]=v[r[i-1]]+(str[r[i]]!=str[r[i-1]]?1:0);
	for(int k=1;k<(1<<n);k<<=1)
	{
		auto cmp=[&](int i,int j)
		{
			return v[i]==v[j]?v[i^k]<v[j^k]:v[i]<v[j];
		};
		sort(r,r+(1<<n),cmp);
		for(int i=1;i<(1<<n);i++) tmp[r[i]]=tmp[r[i-1]]+(cmp(r[i-1],r[i])?1:0);
		copy(tmp,tmp+(1<<n),v);
	}
	for(int i=0;i<(1<<n);i++) printf("%c",str[i^r[0]]);
	puts("");
	return 0;
}