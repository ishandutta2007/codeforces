#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int N=5e5+10,inf=2e9;
int n,m;
char s[N][9],t1[9],t2[9];
map<string,int> q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int qwq;
	cin>>qwq;
	while(qwq--)
	{
		cin>>n;
		q.clear();
		for(int i=1;i<=n;++i)
		{
			cin>>s[i];
			++q[s[i]];
		}
		for(int i=1;i<=n;++i)
		{
			--q[s[i]];
			int m=strlen(s[i]);
			bool flag=0;
			for(int j=0;j<m-1;++j)
			{
				for(int k=0;k<=j;++k) t1[k]=s[i][k];
				t1[j+1]=0;
				for(int k=j+1;k<m;++k) t2[k-j-1]=s[i][k];
				t2[m-j-1]=0;
			//cout<<t1<<' '<<t2<<"!!!"<<endl;
				if(q[t1]>0&&q[t2]>0) flag=1;
			}
			cout<<flag;
			++q[s[i]];
		}
		cout<<'\n';
	}
	return 0;
}