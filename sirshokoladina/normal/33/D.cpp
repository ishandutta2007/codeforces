#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <deque>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

bool a[2000][2000];

long long X[2000],Y[2000],x[2000],y[2000],r[2000];

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	forn(i,n)
		cin>>X[i]>>Y[i];
	forn(i,m)
		cin>>r[i]>>x[i]>>y[i];
	forn(i,n)
		forn(j,m)
			a[i][j] = ( (X[i]-x[j])*(X[i]-x[j]) + (Y[i]-y[j])*(Y[i]-y[j]) < r[j]*r[j] );
	forn(i,k){
		int s,t;
		cin>>s>>t;
		s--; t--;
		int q=0;
		forn(j,m)
			q+= (a[s][j]^a[t][j]);
		cout<<q<<endl;
	}
	return 0;
}