#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
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
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
string sente="Stannis",gote="Daenerys";
int main()
{
	int odd=0,even=0,n,k,a;
	scanf("%d %d",&n,&k);
	rep(i,n){
		scanf("%d",&a);
		if(a%2>0) odd++;else even++;
	}
	if(n==k){
		if(odd%2>0) cout<<sente<<endl;
		else cout<<gote<<endl;
	}
	else{
		if(abs(odd-even)<k){
			if((n+k)%2>0) cout<<sente<<endl;
			else cout<<gote<<endl;
		}
		else{
			if(k%2>0 && odd>even) cout<<sente<<endl;
			else cout<<gote<<endl;
		}
	}
}