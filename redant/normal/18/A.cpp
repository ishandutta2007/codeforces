/*
LANG: C++
ID: AnilKishore
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define FILL(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI(x) scanf("%d",&x)
#define EQ(x,y) ((abs(x-y))<1e-8)

int x[3],y[3];
double num[3], den[3];

int right()
{
	int i,j,z=0,inf=0;
	for(i=0;i<3;i++)
	{
		j = (i+1)%3;
		num[i] = y[i]-y[j];
		den[i] = x[i]-x[j];
		if(num[i]==0 && den[i]==0) return 0;
		if(num[i]<0 && den[i]<0) num[i]*=-1, den[i]*=-1;
		else if(num[i]<0||den[i]<0) num[i]=-1*abs(num[i]), den[i]=abs(den[i]);
	}

	for(i=0;i<3;i++)
	{
		j = (i+1)%3;
		if(num[i]==num[j] && den[i]==den[j]) return 0;
		if(num[i]==0 && den[j]==0) return 1;
		if( (num[i]*num[j]) == -1*(den[i]*den[j]) ) return 1;
	}

	return 0;
}

int main()
{
	int i,j,almst;
	SI(x[0]); SI(y[0]);
	SI(x[1]); SI(y[1]);
	SI(x[2]); SI(y[2]);
	
	if(right()){ puts("RIGHT"); return 0; }
	else
	{
		almst=0;

		for(i=0;i<3;i++)
		{ 
			x[i]++; if(right()) almst=1; x[i]--;
			x[i]--; if(right()) almst=1; x[i]++;
		}
		
		for(i=0;i<3;i++)
		{ 
			y[i]++; if(right()) almst=1; y[i]--;
			y[i]--; if(right()) almst=1; y[i]++;
		}

		if(almst)
		{
			puts("ALMOST");
			return 0;
		}
	}

	
	puts("NEITHER");
	
	return 0;
}