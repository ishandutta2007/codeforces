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
lint num[70],num2[70];
int a[252521];
int main()
{
	int n,k,t;lint x;lint out=0;
	scanf("%d %d %d",&n,&k,&t);
	rep(i,n){
		scanf("%d",&x);a[i]=x;
	}
	rep(i,n){
		x=a[i];
		rep(j,64){
			num[j]+=(x&1);
			x/=2;
		}
	}
	//rep(i,3) cout<<num[i]<<endl;
	rep(i,n){
		rep(j,68) num2[j]=num[j];
		x=a[i];
		rep(j,64){
			num2[j]-=(x&1);
			x/=2;
		}
		x=a[i];
		rep(j,k) x*=t;
		rep(j,66){
			num2[j]+=(x&1);
			x/=2;
		}
		lint now=0;
		rep(j,66){
			if(num2[j]>0) now+=1LL<<j;
		}
		out=max(out,now);
	}
	cout<<out<<endl;
}