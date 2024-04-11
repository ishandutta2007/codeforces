#include<iostream>

using namespace std;

const int V=100;
const int N=12;
const int L=4096;

int n,m,q;

int w[V+7];
int s[L+7];

//int dp[N+1][V+7][V+7];
//bool b[N+1][V+7][V+7];

//int solve(int pos,)


int res[L+7][V+7];

void solve(int num)
{
	int x,i,j,p;

	for(i=0;i<(1<<n);i++)
	{
		x=num^i;
		p=0;

		//cout<<x<<" ---- "<<i<<endl;

		for(j=0;j<n;j++)
		{
			if(!(x&(1<<(n-j-1))))
				p+=w[j];
		}

		if(p<=V)res[num][p]+=s[i];
	}
}

int main ()
{
	int i,p,x,j;
	string str;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m>>q;

	for(i=0;i<n;i++)
		cin>>w[i];

	for(i=0;i<m;i++)
	{
		cin>>str;

		p=0;

		for(j=0;j<n;j++)
			if(str[j]=='1')
				p+=(1<<(n-j-1));

		s[p]++;
	}

	for(i=0;i<(1<<n);i++)
	{
		solve(i);
		//cout<<res[i][20]<<" "<<i<<endl;
		//cout<<res[i][0]<<" p0p "<<i<<endl;
		for(j=1;j<=V;j++)
			res[i][j]+=res[i][j-1];
	}

	for(i=0;i<q;i++)
	{
		cin>>str>>x;

		p=0;

		for(j=0;j<n;j++)
			if(str[j]=='1')
				p+=(1<<(n-j-1));

		//cout<<p<<endl;

		cout<<res[p][x]<<"\n";
	}

	return 0;
}