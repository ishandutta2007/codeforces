#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair

int main(){
	int t;
	cin>>t;
	forn(i,t){
		long long n,m,a,b,x1,y1,x2,y2;
		cin>>n>>m>>x1>>y1>>x2>>y2;
		a=abs(x2-x1);
		b=abs(y2-y1);
		cout<<n*m-(2*(n-a)*(m-b)-max((long long)0,n-a-a)*max((long long)0,m-b-b))<<endl;
	}
	return 0;
}