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

long long x1[200],x2[200],y1[200],y2[200],a[200];
long double comx[200][200], comy[200][200];
long double m[200][200];

int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	int n;
	cin>>n;
	forn(i,n){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		if(x1[i]>x2[i])
			swap(x1[i],x2[i]);
		if(y1[i]>y2[i])
			swap(y1[i],y2[i]);
		a[i]=(x2[i]-x1[i]);
	}
	forn(j,n)
		ford(i,j+1){
			if(i==j){
				m[i][j]=a[i]*a[i]*a[i];
				comx[i][j]=((long double)(x1[i]+x2[i]))/2;
				comy[i][j]=((long double)(y1[i]+y2[i]))/2;
				continue;
			}
			m[i][j]=m[i][j-1]+m[j][j];
			comx[i][j]=(comx[i][j-1]*m[i][j-1]+comx[j][j]*m[j][j])/m[i][j];
			comy[i][j]=(comy[i][j-1]*m[i][j-1]+comy[j][j]*m[j][j])/m[i][j];
		}
	int mn=n;
	forn(j,n)
		for(int i=1; i<=j; i++)
			if(comx[i][j]<x1[i-1] || comx[i][j]>x2[i-1] || comy[i][j]<y1[i-1] || comy[i][j]>y2[i-1])
				mn=min(mn,j);
	cout<<mn;
	return 0;
}