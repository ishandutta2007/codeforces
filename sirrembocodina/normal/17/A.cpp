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

vector<int> p;

int main(){
	// freopen("input.txt","rt",stdin);
	// freopen("output.txt","wt",stdout);
	int n,k;
	cin>>n>>k;
	forab(i,2,n+1){
		bool pr=true;
		for(int j=0;(j<p.size())&&(p[j]*p[j]<=n);j++)
			if(i%p[j]==0)
				pr=false;
		if(!pr)
			continue;
		p.pb(i);
		forn(j,p.size()-2)
			if(p[j]+p[j+1]+1==i){
				k--;
				break;
			}
	}
	if(k>0)
		cout<<"NO";
	else
		cout<<"YES";
}