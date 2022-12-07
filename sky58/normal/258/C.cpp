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
int mi[110000];
vector <int> a;
vector <int> ya[100010];
lint mo=1000000007;
lint zyo(lint x,lint y){
    lint ret=1,a=x;
    while(y>0){
    	if(y%2==1) ret=(ret*a)%mo;
    	a=(a*a)%mo;y/=2;
    }
    return ret;
}
int main()
{
	int n,i,j,x;lint out=0;
	cin>>n;
	rep(i,n){
		cin>>x;a.pb(x);
	}
	sort(All(a));
	memset(mi,0,sizeof(mi));
	rep(i,n) mi[a[i]]=max(mi[a[i]],n-i);
	for(i=100000;i>0;i--) mi[i-1]=max(mi[i],mi[i-1]);
	//cout<<"a"<<endl;
	
	REP(i,1,100001) for(j=i;j<100001;j+=i) ya[j].pb(i);
	REP(i,1,100001){
		vector <int> ba;
		/*for(j=1;j*j<=i;j++){
			if(i%j==0) ya.pb(j);
			if(j*j<i) ya.pb(i/j);
		}*/
		int m=ya[i].size();lint ret=1,ret2=1;
		rep(j,m) ba.pb(mi[ya[i][j]]);
		ba.pb(0);reverse(All(ba));
		rep(j,m) ret=(ret*zyo(m-j,ba[j+1]-ba[j]))%mo;
		ba[1]=0;rep(j,m) ret2=(ret2*zyo(m-j,ba[j+1]-ba[j]))%mo;
		out=(out+mo+ret-ret2)%mo;
	}
	cout<<(out+1)%mo<<endl;
	return 0;
}