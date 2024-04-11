#include <bits/stdc++.h>
using namespace std;
int n,m;
int NN;
vector <int> input[300000],now;
int ind,ind2;
int cnt(int ss)
{
	int ncnt,mcnt=0;
	for(int i=0;i<n;i++)
	{
		ncnt=0;
		for(int j=0;j<m;j++)if(input[i][j]!=now[j])
			ncnt++;
		if(mcnt<ncnt)
		{
			if(ss)
				ind=i;
			mcnt=ncnt;
		}
	}
	return mcnt;
}
int imsi;
int cnt2()
{
	int ncnt,mcnt=0;
	imsi=0;
	for(int i=0;i<n;i++)
	{
		ncnt=0;
		for(int j=0;j<m;j++)if(input[i][j]!=now[j])
			ncnt++;
		if(ncnt==3&&input[i][ind2]!=now[ind2]&&(!imsi||imsi==input[i][ind2]))
		{
			imsi = input[i][ind2];
			ncnt=2;
		}
		mcnt=max(mcnt,ncnt);
	}
	return mcnt;
}
void shw()
{
	NN=1;
	printf("Yes\n");
	for(int x : now)
		printf("%d ",x);
}
void fir()
{
	int mcnt=cnt(1);
	if(mcnt<=2)
	{
		shw();
		return;
	}
	else if(mcnt==3)
	{
		vector <int> mind;
		for(int j=0;j<m;j++)if(input[ind][j]!=now[j])
			mind.push_back(j);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)if(i!=j)
			{
				now[mind[i]] = input[ind][mind[i]];
				now[mind[j]] = 0;
				ind2=mind[j];
				if(cnt2()<=2)
				{
					if(imsi)
						now[mind[j]]=imsi;
					else
						now[mind[j]]=input[0][mind[j]];
					shw();
					return;
				}
				now[mind[i]] = input[0][mind[i]];
				now[mind[j]] = input[0][mind[j]];
			}
		}
	}
	else if(mcnt==4)
	{
		vector <int> mind;
		for(int j=0;j<m;j++)if(input[ind][j]!=now[j])
			mind.push_back(j);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<i;j++)
			{
				now[mind[i]] = input[ind][mind[i]];
				now[mind[j]] = input[ind][mind[j]];
				if(cnt(0)<=2)
				{
					shw();
					return;
				}
				now[mind[i]] = input[0][mind[i]];
				now[mind[j]] = input[0][mind[j]];
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		input[i].resize(m);
		for(int j=0;j<m;j++)
			scanf("%d",&input[i][j]);
	}
	now = input[0];
	fir();
	if(!NN)
		printf("No");
	return 0;
}