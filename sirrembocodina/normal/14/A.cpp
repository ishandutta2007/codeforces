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

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n,m,l,r,u,d;
	bool a[60][60];
	char c;
	string s;
	cin>>n>>m;
	l=m;
	r=0;
	u=n;
	d=0;
	forn(i,n){
		forn(j,m){
			cin>>c;
			a[i][j]=c=='*';
			if(a[i][j]){
				l=min(l,j);
				r=max(r,j);
				u=min(u,i);
				d=max(d,i);
			}
		}
		getline(cin,s);
	}
	forab(i,u,d+1){
		forab(j,l,r+1)
			if(a[i][j])
				cout<<"*";
			else
				cout<<".";
		cout<<endl;
	}
}