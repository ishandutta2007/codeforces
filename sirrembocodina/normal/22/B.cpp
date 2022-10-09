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

bool used[50][50];

int main(){
	// freopen("input.txt","rt",stdin);
	// freopen("output.txt","wt",stdout);
	int n,m;
	cin>>n>>m;
	forn(i,n){
		string s;
		forn(j,m){
			char c;
			cin>>c;
			used[i][j]=c=='1';
		}
		getline(cin,s);
	}
	int ans=0;
	forn(i1,n)
		forn(j1,m)
			forab(i2,i1,n)
				forab(j2,j1,m){
					bool ok=true;
					forab(i,i1,i2+1)
						forab(j,j1,j2+1)
							if(used[i][j])
								ok=false;
					if(ok)
						ans=max(ans,2*(i2-i1+j2-j1)+4);
				}
	cout<<ans;
}