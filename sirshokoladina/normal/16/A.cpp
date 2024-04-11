#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

string s[200];

int main(){
	int n,m;
	cin>>n>>m;
	forn(i,n)
		cin>>s[i];
	bool q=1;
	forn(i,n)
		forn(j,m-1)
			if(s[i][j]!=s[i][j+1])
				q=0;
	forn(i,n-1)
		if(s[i][0]==s[i+1][0])
			q=0;
	if(q)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}