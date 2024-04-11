#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int x,y;
	cin>>x>>y;
	int a=0;
	while(a*a<x*x+y*y)
		a++;
	if( (a*a==x*x+y*y) || (x==0) || (y==0) || ((a%2)^(x<0)^(y<0)) )
		cout<<"black";
	else
		cout<<"white";
	return 0;
}