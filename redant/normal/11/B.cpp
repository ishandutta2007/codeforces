/*
PROG: CF#11-JumpingJack
LANG: C++
ID: Anil Kishore
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

#define INF 100000000
#define PB push_back
#define MP make_pair
#define LL long long
#define FILL(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI(x) scanf("%d",&x)

int main()
{
	LL x,c,a,s=1,k=1;
	int i,j,r=0;
	
	cin>>x;
	
	if(x==0ll)
	{ 
		cout<<"0"<<endl;
		return 0;
	}
	
	if(x<0) x*=-1;
	
	while(!(s<=x && s+k+1>x)){ k++; s+=k; }
	
	if(s==x) r=k;
	else if(k%2)
	{
		if((x-s)%2) r=k+2;
		else r=k+1;
	}
	else
	{
		if((x-s)%2) r=k+1;
		else r=k+3;
	}
	
	cout<<r<<endl;	
	
	return 0;
}