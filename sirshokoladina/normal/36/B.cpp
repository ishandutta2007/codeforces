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

char c1[10][10];
char ci[1000][1000];

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int n, k;
	cin>>n>>k;
	k--;
	forn(i,n)
		forn(j,n){
			cin>>c1[i][j];
			ci[i][j]=c1[i][j];
		}
	int ni=n;
	forn(iii,k){
		ford(i,n)
			ford(j,n)
				forn(x,ni)
					forn(y,ni)
						if(c1[i][j]=='.' && ci[x][y]=='.')
							ci[i*ni+x][j*ni+y]='.';
						else
							ci[i*ni+x][j*ni+y]='*';
		ni*=n;			
	}
	forn(i,ni){
		forn(j,ni)
			cout<<ci[i][j];
		cout<<endl;
	}
	return 0;
}