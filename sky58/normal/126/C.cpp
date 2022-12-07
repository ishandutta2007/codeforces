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
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int ty[2100],tt[2100],by[2100],bt[2100];
string s[2100];
int tcal(int x,int y){
	if(((s[x][y]-'0')+ty[x]+tt[y])%2>0){
		ty[x]++;tt[y]++;return 1;
	}
	return 0;
}
int bcal(int x,int y){
	if(((s[x][y]-'0')+by[x]+bt[y])%2>0){
		by[x]++;bt[y]++;return 1;
	}
	return 0;
}
int main()
{
	int i,j,n,out=0;
	cin>>n;rep(i,n) cin>>s[i];
	rep(i,2100) bt[i]=by[i]=tt[i]=ty[i]=0;
	rep(i,n) for(j=n-1;j>i;j--){
		out+=tcal(i,j);
//		if(j>0) out+=tcal(i,n-i-j);
		out+=bcal(j,i);
//		if(j>0) out+=bcal(i,n-i-j);
	}
	rep(i,n){
		out+=((s[i][i]-'0')+ty[i]+tt[i]+by[i]+bt[i])%2;
	}
	cout<<out<<endl;return 0;
}