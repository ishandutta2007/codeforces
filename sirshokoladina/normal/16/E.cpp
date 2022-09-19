#include <iostream>
#include <cstdio>
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

long double a[20][20];
int k[500000];
vector<int> m[20];
long double p[500000];

int main(){
	int n;
	cin>>n;
	forn(i,n)
		forn(j,n)
			cin>>a[i][j];
	k[0]=0;
	forn(mask,1<<n){
		k[mask]=k[mask/2]+mask%2;
		m[k[mask]].pb(mask);
		p[mask]=0;
	}
	p[(1<<n)-1]=1;
	for(int K=n;K>1;K--)
		forn(i,m[K].size())
			forn(x,n)
				if(m[K][i]&(1<<x))
					forn(y,n)
						if(m[K][i]&(1<<y) && x!=y)
							p[m[K][i]-(1<<y)]+=p[m[K][i]]*(2./K/(K-1))*a[x][y];
	forn(i,n)
		printf("%0.8f ",(double)p[1<<i]);
	return 0;
}