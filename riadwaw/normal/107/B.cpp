#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
/**
 CAUTION Is int really int?
 * 
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main() {
#ifdef DEBUG
	freopen("input", "r", stdin);
	//freopen("output","w",stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
	solve();
	return 0;
}
void solve() {
	int n,m,h;
	cin>>n>>m>>h;
	int s[1011];
	int sm=0;
	for(int i=0;i<m;++i){
		cin>>s[i];
		sm+=s[i];
	}
	 // C(sum-1,n-1)
	//C(sum-m,n); sum-1-(sum-m)=m-1
	if(sm<n){
		cout<<-1;
		return;
	}
	double ans =1;
	
	if(n-1>sm-s[h-1]){
		cout<<1;
		return;
	}
	
	for(int i=1;i<=n-1;++i)
	{
		ans/=sm-n+i;ans*=i;
	}
		//c(2,1)
	for(int i=1;i<=n-1;++i){
		ans/=i;
		ans*=sm-s[h-1]-n+1+i;
	}
	printf("%.10lf", 1-ans);
}