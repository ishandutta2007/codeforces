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
string s[100];
lint fib[100];
int main()
{
	/*s[0]="1";s[1]="2";
	REP(i,2,20) s[i]=s[i-2]+s[i-1];
	rep(i,20){
		int o=0,t=0,oo=0,ot=0,to=0,tt=0;
		rep(j,s[i].size()){
			if(s[i][j]=='1') o++;else t++;
		}
		rep(j,s[i].size()-1){
			if(s[i][j]=='1' && s[i][j+1]=='1') oo++;
			if(s[i][j]=='1' && s[i][j+1]=='2') ot++;
			if(s[i][j]=='2' && s[i][j+1]=='1') to++;
			if(s[i][j]=='2' && s[i][j+1]=='2') tt++;
		}
		cout<<o<<' '<<t<<' '<<ot<<' '<<to<<' '<<tt<<endl;
	}*/
	fib[0]=fib[1]=1;
	REP(i,2,100) fib[i]=fib[i-1]+fib[i-2];//cout<<fib[50]<<endl;
	int K,n,m;lint x;
	cin>>K>>x>>n>>m;
	lint o=fib[K-3],t=fib[K-2],ot=o,to=fib[K-3],tt=0;
	if(K>=4){
		tt=fib[K-4];if(K%2==0) tt--;
	}
	if(K%2==1) to--;
	rep(i,51) rep(j,51) rep(k,4) rep(l,4){
		int l1=i*2+__builtin_popcount(k),l2=j*2+__builtin_popcount(l);
		if(l1>n || l2>m) continue;
		lint sum=o*i+t*j;
		if(k/2>0 && l%2>0) sum+=ot;
		if(l/2>0 && k%2>0) sum+=to;
		if(l/2>0 && l%2>0) sum+=tt;
		if(sum==x){
			string s1="",s2="";
			if(k%2>0) s1+="C";rep(i2,i) s1+="AC";rep(i2,n-l1) s1+="B";if(k/2>0) s1+="A";
			if(l%2>0) s2+="C";rep(i2,j) s2+="AC";rep(i2,m-l2) s2+="B";if(l/2>0) s2+="A";
			cout<<s1<<endl;cout<<s2<<endl;return 0;
		}
	}
	cout<<"Happy new year!"<<endl;
}