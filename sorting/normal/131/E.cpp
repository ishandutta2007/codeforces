#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

pair<int, int> p[N];
vector<int> row[N],col[N],diag[2][N];
int score[N],res[9];

bool cmp(int a,int b)
{
	return p[a]<p[b];
}

int main ()
{
	int n,m;
	int i,j;

	cin>>n>>m;

	for(i=0;i<m;i++)
		cin>>p[i].first>>p[i].second;

	for(i=0;i<m;i++)
	{
		row[p[i].first].push_back(i);
		col[p[i].second].push_back(i);
		diag[0][p[i].first+p[i].second-1].push_back(i);
		diag[1][p[i].first-p[i].second+n].push_back(i);
	}

	for(i=1;i<=n;i++)
	{
		if(!row[i].empty())
			sort(row[i].begin(),row[i].end(),cmp);
		if(!col[i].empty())
			sort(col[i].begin(),col[i].end(),cmp);
	}

	for(i=1;i<2*n;i++)
	{
		if(!diag[0][i].empty())
			sort(diag[0][i].begin(),diag[0][i].end(),cmp);
		if(!diag[1][i].empty())
			sort(diag[1][i].begin(),diag[1][i].end(),cmp);
	}

	for(i=1;i<=n;i++)
	{
		if(row[i].size()>=2)
		{
			for(j=0;j<row[i].size();j++)
			{
				if(j==0 || j==row[i].size()-1)
					score[row[i][j]]++;
				else
					score[row[i][j]]+=2;
			}
		}

		if(col[i].size()>=2)
		{
			for(j=0;j<col[i].size();j++)
			{
				if(j==0 || j==col[i].size()-1)
					score[col[i][j]]++;
				else
					score[col[i][j]]+=2;
			}
		}
	}

	for(i=1;i<2*n;i++)
	{
		if(diag[0][i].size()>=2)
		{
			for(j=0;j<diag[0][i].size();j++)
			{
				if(j==0 || j==diag[0][i].size()-1)
					score[diag[0][i][j]]++;
				else
					score[diag[0][i][j]]+=2;
			}
		}

		if(diag[1][i].size()>=2)
		{
			for(j=0;j<diag[1][i].size();j++)
			{
				if(j==0 || j==diag[1][i].size()-1)
					score[diag[1][i][j]]++;
				else
					score[diag[1][i][j]]+=2;
			}
		}
	}

	for(i=0;i<m;i++)
		res[score[i]]++;

	for(i=0;i<=8;i++)
		cout<<res[i]<<" ";
	cout<<"\n";
	
	return 0;
}