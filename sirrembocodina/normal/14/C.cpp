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
#define pt pair<int,int>
#define otr pair<pt,pt>


int main(){
//	freopen("input.txt","rt",stdin);
//	freopen("output.txt","wt",stdout);
	otr a[4];
	int k[4],u[4];
	forn(i,4)
		k[i]=0;
	forn(i,4)
		u[i]=0;
	forn(i,4)
		cin>>a[i].fs.fs>>a[i].fs.sc>>a[i].sc.fs>>a[i].sc.sc;
	forn(i,4)
		forn(j,4)
			if((i!=j)&&((a[i].fs==a[j].fs)||(a[i].fs==a[j].sc)||(a[i].sc==a[j].fs)
					||(a[i].sc==a[j].sc))){
				k[i]++;
				if(((a[i].fs.fs-a[i].sc.fs)*(a[j].fs.fs-a[j].sc.fs)!=
					-(a[i].fs.sc-a[i].sc.sc)*(a[j].fs.sc-a[j].sc.sc))){
					cout<<"NO";
					return 0;
				}
			}
	
	forn(i,4)
		if(k[i]!=2){
			cout<<"NO";
			return 0;
		}
	forn(i,4)
		forn(j,4)
			if((i!=j)&&(a[i]==a[j])){
				cout<<"NO";
				return 0;
			}
	forn(i,4)
		forn(j,4)
			if((i!=j)&&(abs(a[i].fs.fs-a[i].sc.fs)==abs(a[j].fs.fs-a[j].sc.fs))&&
				(abs(a[i].fs.sc-a[i].sc.sc)==abs(a[j].fs.sc-a[j].sc.sc)))
				u[i]++;
	forn(i,4)
		if(u[i]!=1){
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
}