#include <bits/stdc++.h>
using namespace std;
int cal(vector<int> &a)
{
	int n=a.size(),i,j;
	if (n<=1) return 0;
	for (i=0;i<n;i++) if (a[i]) break;
	if (i==n) return 0;
	vector<int> buc[31];
	int f[31];
	bool flg=0;
	memset(f,0,sizeof f);
	for (i=0;i<n;i++) if (a[i])
	{
		int x=31-__builtin_clz(a[i]);
		buc[x+1].push_back(a[i]^1<<x);
	} else buc[0].push_back(0);
	for (j=0;j<=30;j++) if (buc[j].size()) f[j]=cal(buc[j]);
	int tot=0,ans=n,cc=-2;
	for (j=0;j<=30;j++) if (buc[j].size()) tot+=buc[j].size()-1;
	ans=tot;
	for (j=0;j<=30;j++) if (buc[j].size()) ans=min(ans,tot-((int)buc[j].size()-1)+f[j]+flg+max(++cc,0));
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i;
	cin>>n;
	vector<int> a(n);
	for (int &x:a) cin>>x;
	sort(a.begin(),a.end());
	cout<<cal(a)<<endl;
}