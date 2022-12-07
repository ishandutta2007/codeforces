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
int n;
vector<int> a,b,c,d;
template <class typ> struct BIT{
	vector<typ> x;
	BIT(int n):x(n,0){}
	//[a,b]
	typ sum(int a,int b){
		if(a==0){
			typ s=0;
			for(int i=b;i>=0;i=(i&(i+1))-1) s+=x[i];
			return s;
		}
		else return sum(0,b)-sum(0,a-1);
	}
	void add(int ind,typ f){
		for(int i=ind;i<x.size();i|=i+1) x[i]+=f;
	}
};
vector<int> dec(vector<int> in){
	vector<int> ret;
	BIT<int> bit(n+10);
	rep(i,n){
		ret.pb(in[i]-bit.sum(0,in[i]));
		bit.add(in[i],1);
	}
	return ret;
}
vector<int> enc(vector<int> in){
	vector<int> ret;
	BIT<int> bit(n+10);
	rep(i,n){
		int lo=0,hi=n-1;
		while(hi>lo){
			int mi=(lo+hi)/2;
			if(mi-bit.sum(0,mi)<in[i]) lo=mi+1;else hi=mi;
		}
		ret.pb(lo);bit.add(lo,1);
	}
	return ret;
}
int main(){
	cin>>n;int x;
	rep(i,n){
		cin>>x;a.pb(x);
	}
	rep(i,n){
		cin>>x;b.pb(x);
	}
	c=dec(a);d=dec(b);
	rep(i,n) c[i]+=d[i];
	reverse(All(c));
	REP(i,1,n){
		c[i]+=c[i-1]/i;
		c[i-1]%=i;
	}
	c[n-1]%=n;
	reverse(All(c));
	d=enc(c);
	rep(i,n){
		cout<<d[i];
		if(i<n-1) cout<<' ';else cout<<endl;
	}
}