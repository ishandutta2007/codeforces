#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=n-1;i>=0;i--)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pi 3.1415926535897932

int a[110][110];

int main(){
	int n,m;
	cin>>n>>m;
	forn(i,n){
		string s;
		cin>>s;
		forn(j,m)
			a[i][j]=s[j]-'0';
	}
	bool fuck=true;
	forn(i,n)
		forn(j,m-1)
			if(a[i][j]!=a[i][j+1])
				fuck=false;
	forn(i,n-1)
		if(a[i][0]==a[i+1][0])
			fuck=false;
	if(fuck)
		cout<<"YES";
	else
		cout<<"NO";
}