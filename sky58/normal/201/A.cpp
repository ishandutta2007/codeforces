#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	int i,x;
	cin>>x;
	/*if(x%4<2){
		x=x/4;
		for(i=0;;i++){
			if((i*i+1)/2>=x){
				cout<<i*2+1<<endl;return 0;
			}
		}
	}
	else{
		for(i=0;;i++){
			if((i*i+1)/2*4+i/2*4>x){
				cout<<i*2+1<<endl;return 0;
			}
		}
	}*/
	if(x==3){cout<<"5"<<endl;return 0;}
	for(i=1;;i+=2){
		if((i*i+1)/2>=x){
			cout<<i<<endl;return 0;
		}
	}
	return 0;
}