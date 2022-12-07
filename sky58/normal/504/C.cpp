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
map<int,int> me,m2;
int n;
int a[114514];
lint cal(void){
	int pa=0,f=0;
	map<int,int>::iterator it=me.begin();
	while(it!=me.end()){
		if(((*it).se)%2>0) pa++;it++;
	}
	if(pa>1) return 0;
	rep(i,n/2){
		if(a[i]!=a[n-1-i]) f=1;
	}
	if(f<1) return (lint)n*(n+1)/2;
	int le=0,ri=0,bo=0;
	while(le<n/2){
		m2[a[le]]++;
		if(m2[a[le]]*2>me[a[le]]) break;
		le++;
	}
	if(le*2+1==n && me[a[le]]%2==1) le++;
	while(le>=(n+1)/2 && le<n-1){
		if(a[le]!=a[n-1-le]) break;le++;
	}
	m2.clear();
	while(ri<n/2){
		m2[a[n-1-ri]]++;
		if(m2[a[n-1-ri]]*2>me[a[n-1-ri]]) break;
		ri++;
	}
	if(ri*2+1==n && me[a[ri]]%2==1) ri++;
	while(ri>=(n+1)/2 && ri<n-1){
		if(a[ri]!=a[n-1-ri]) break;ri++;
	}
	while(bo<n/2){
		if(a[bo]!=a[n-1-bo]) break;
		bo++;
	}
	//cerr<<le<<' '<<ri<<' '<<bo<<endl;
	lint ret=0;
	rep(i,le+1){
		if(i==0) ret+=ri+1;
		else if(i<=bo) ret+=min(ri+1,n-i);
		else ret+=min(bo+1,n-i);
	}
	//if(n==90767) cout<<le<<' '<<ri<<' '<<bo<<endl;
	return ret;
}
int main()
{
	cin>>n;
	rep(i,n){
		cin>>a[i];me[a[i]]++;
	}
	cout<<cal()<<endl;
}