#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define FILL(a,v) memset(a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define INT long long
#define UINT unsigned long long
#define Uint unsigned int
#define PII pair<INT,INT>
#define SZ(a) ((int)(a).size())
#define _X first
#define _Y second
#define OVER(a) return puts(a),0
using namespace std;
using namespace __gnu_cxx;

int fnshu[60]={25,18,15,12,10,8,6,4,2,1,0,0,0};

struct person
{
	string name;
	int score;
	int mints[100];
};

person pers[3500];
bool srt1(person a,person b)
{
	if(a.score>b.score)return true;
	if(a.score<b.score)return false;
	for(int i=0;i<100;i++)
	{
		if(a.mints[i]>b.mints[i])return true;
		if(a.mints[i]<b.mints[i])return false;
	}
}
bool srt2(person a,person b)
{
	if(a.mints[0]>b.mints[0])return true;
	if(a.mints[0]<b.mints[0])return false;
	if(a.score>b.score)return true;
	if(a.score<b.score)return false;
	for(int i=1;i<100;i++)
	{
		if(a.mints[i]>b.mints[i])return true;
		if(a.mints[i]<b.mints[i])return false;
	}
}

int t;
int main()
{
	cin>>t;
	int n,cnt;
	string nam;
	map<string,int> dy;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>nam;
			if(!dy.count(nam))dy[nam]=cnt,cnt++;
			pers[dy[nam]].name=nam;
			pers[dy[nam]].mints[j]++;
			pers[dy[nam]].score+=fnshu[j];
		}
	}
	sort(pers,pers+cnt,srt1);
	cout<<pers[0].name<<endl;
	sort(pers,pers+cnt,srt2);
	cout<<pers[0].name<<endl;
	return 0;
}