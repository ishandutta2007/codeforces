#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;


vector < pair <int , int > > v;

void input();
void solve();




int main()
    {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
    }


void input()
    {
	scanf("%d%d",&n,&m);
    }


void solve()
    {
	int i;
	int j;
	j=min(n,m);
	i=0;
	v.push_back(make_pair(i,j));
	int br=1;
	while(j!=0)
		{
		j--;
		i++;
		v.push_back(make_pair(i,j));
		br++;
		}
	printf("%d\n",br);
	while(1)
		{
		br--;
		printf("%d %d\n",v[br].first,v[br].second);
		if(br==0)break;
		}
    }