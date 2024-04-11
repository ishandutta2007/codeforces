#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int a[110][110];

bool ok(int x,int y,int m){
	bool b=true;
	forn(i,m)
		if(a[x][y+i])
			b=false;
	return b;
}

int f(int x,int y,int c,int m){
	int ans=0;
	forn(i,m)
		ans+=abs(x+1-c)+abs(y+i+1-c);
	return ans;
}

int main(){       
	int n,k;
	cin>>n>>k;
	int c=k/2+1;
	forn(i,k)
		forn(j,k)
			a[i][j]=false;
	forn(i,n){
		int m,min2,x=-1,y=-1;
		cin>>m;   
		min2=100000000;     
		forn(i,k)
			forn(j,k-m+1)
				if(ok(i,j,m)&&(f(i,j,c,m)<min2)){
					x=i;
					y=j;
					min2=f(i,j,c,m);
				}
		if(x<0)
			cout<<-1<<endl;
		else{
			cout<<x+1<<" "<<y+1<<" "<<y+m<<endl;
			forn(i,m){
				a[x][y+i]=true;
			}
		}
	}
}