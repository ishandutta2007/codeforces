#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int n,m;
char c;
char a[123][123];
pair<int,int> wayzh[12000];
map<char,int> cm;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d %d %c\n",&n,&m,&c);
	for(int i=0;i<n;i++)scanf("%s",a[i]);
	int cn01=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]==c)wayzh[cn01++]=make_pair(i,j);
	cm[c]++;
	int cn_t=0;
	for(int i=0;i<cn01;i++)
	{
		int y=wayzh[i].first;
		int x=wayzh[i].second;
		if(y!=0&&a[y-1][x]!='.'&&!cm.count(a[y-1][x]))
		{
			cm[a[y-1][x]]++;
			cn_t++;
		} 
		if(x!=m-1&&a[y][x+1]!='.'&&!cm.count(a[y][x+1]))
		{
			cm[a[y][x+1]]++;
			cn_t++;
		} 
		if(y!=n-1&&a[y+1][x]!='.'&&!cm.count(a[y+1][x]))
		{
			cm[a[y+1][x]]++;
			cn_t++;
		} 
		if(x!=0&&a[y][x-1]!='.'&&!cm.count(a[y][x-1]))
		{
			cm[a[y][x-1]]++;
			cn_t++;
		}
	}
	printf("%d",cn_t);
	return 0;
}