#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)

char a[200][200];

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int main(){
	vector<bool> u(256,0);
	int n,m;
	char c;
	cin>>n>>m>>c;
	forn(i,n)
		forn(j,m)
			cin>>a[i][j];
	int ans=0;
	forn(i,n)
		forn(j,m)
			if(a[i][j]!='.' && a[i][j]!=c)
				forn(d,4)
					if(i+dx[d]>=0 && i+dx[d]<n && j+dy[d]>=0 && j+dy[d]<m)
						if(a[i+dx[d]][j+dy[d]]==c)
							if(!u[(int)a[i][j]]){
								ans++;
								u[(int)a[i][j]]=1;
							}
	cout<<ans;
	return 0;
}