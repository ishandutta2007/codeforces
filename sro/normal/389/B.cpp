#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define pb push_back
#define mp make_pair
#define FILL(a,v) memset(a,v,sizeof(a))
#define ALL(a) (a).begin(),(a).end()
#define p pair<int,int> 
#define x first
#define y second
using namespace std;
/*
struct p
{
	int x,y;
	p(){}
	p(int x,int y):x(x),y(y) {}
	bool operator<(const p& pp)
	{return (x<pp.x)||((x==pp.x)&&(y<pp.y));}
};
*/
set<p> sp;
int n;
string str[105];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		for(int j=0;j<n;j++)
			if(str[i][j]=='#') sp.insert(p(i,j));
	}
	
	int dx[]={1,1,1,2};
	int dy[]={-1,0,1,0};
	
	while(!sp.empty())
	{
		p pp=*sp.begin();
		sp.erase(sp.begin());
		for(int i=0;i<4;i++)
		{
			int ii=pp.x+dx[i];
			int jj=pp.y+dy[i];
			if(ii>=0&&ii<n&&jj>=0&&jj<n&&sp.count(p(ii,jj)))
				sp.erase(sp.find(p(ii,jj)));
			else
				return puts("NO"),0;
		}
	}
	return puts("YES"),0;
}