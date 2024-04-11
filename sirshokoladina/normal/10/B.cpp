#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define last(a) a[a.size()-1]

int a[200][200];
int d[200][200];
int s[200][200];

int main(){
	int n,k;
	cin>>n>>k;
	int m=(k+1)/2;
	forn(i,k)
		forn(j,k){
			a[i][j]=k-j;
			d[i][j]=abs(i+1-m)+abs(j+1-m);
			if(!j)
				s[i][j]=0;
			s[i][j+1]=s[i][j]+d[i][j];
		}
	forn(t,n){
		int x;
		cin>>x;
		int bx=-1,by=-1,mn=1000000000;
		forn(i,k)
			forn(j,k)
				if(a[i][j]>=x){
					int S=s[i][j+x]-s[i][j];
					if(mn>S){
						mn=S;
						bx=i;
						by=j;
					}
				}
		if(bx==-1)
			cout<<-1<<endl;
		else{
			cout<<bx+1<<' '<<by+1<<' '<<by+x<<endl;
			forn(i,x)
				a[bx][by+i]=0;
			int i=by-1;
			while(i>=0 && a[bx][i]){
				a[bx][i]=by-i;
				i--;
			}
		}
	}
	return 0;
}