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
	int x, y, z;
	cin>>x>>y>>z;
	if(2*z-1>x || 2*z-1>y){
		cout<<0;
		return 0;
	}
	if(2*z-1==x){
		cout<<(y-2*z+3)/2;
		return 0;
	}
	if(2*z-1==y){
		cout<<(x-2*z+3)/2;
		return 0;
	}
	cout<<x+y-4*z+2;
	return 0;
}