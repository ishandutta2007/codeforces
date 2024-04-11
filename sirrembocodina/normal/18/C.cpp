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

vector<int> a;

int main(){
	int n,ans=0;
	int64 sum=0;
	cin>>n;
	a.resize(n);
	forn(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	int64 sl=a[0],sr=sum-a[0];
	forn(i,n-1){
		if(sl==sr)
			ans++;
		sl+=a[i+1];
		sr-=a[i+1];
	}
	cout<<ans;
}