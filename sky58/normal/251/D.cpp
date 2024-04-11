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
typedef pair<lint,int> pint;
//typedef pair<pint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint a[110000],b[110000],c[110000],u[110000];
int r[70],as[70];
int main()
{
	lint sum=0,ret=0;
	int i,j,k,rank=0,n;
	cin>>n;
	rep(i,n){
		cin>>a[i];
		sum^=a[i];u[i]=-1;c[i]=0;
	}
	rep(i,n){
		lint t1=0;
		for(j=61;j>=0;j--){
			if(!(sum&(1LL<<j))){
				t1*=2;if((a[i]&(1LL<<j))) t1++;
			}
		}
		for(j=61;j>=0;j--){
			if((sum&(1LL<<j))){
				t1*=2;if((a[i]&(1LL<<j))) t1++;
			}
		}
		b[i]=t1;
	}
	/*cout<<sum<<endl;
	rep(i,12){
		if((sum&(1<<i))) cout<<'1';else cout<<'0';
	}
	cout<<endl;*/
	//rep(i,n) cout<<b[i]<<' ';cout<<endl;
	for(i=61;i>=0;i--){
		r[i]=-1;lint cur=(1LL<<i);
		//if(sum&cur) continue;
		rep(j,n){if(u[j]<0 && (b[j]&cur)) break;}
		if(j>=n) continue;
		u[j]=i;r[i]=j;as[rank++]=j;c[j]^=cur;
		REP(k,j+1,n){
			if(u[k]<0 && (b[k]&cur)){
				b[k]^=b[j];c[k]^=c[j];
			}
		}
	}
	for(i=rank-1;i>=0;i--){
		j=as[i];
		rep(k,62){
			if((b[j]&(1LL<<k)) && u[j]!=k && r[k]>=0){
				b[j]^=b[r[k]];c[j]^=c[r[k]];
			}
		}
		ret^=c[j];
	}
	//cout<<ret<<endl;
	rep(i,n){
		if(u[i]>=0 && (ret&(1LL<<u[i]))) cout<<'2';else cout<<'1';
		if(i<n-1) cout<<" ";else cout<<endl;
	}
	return 0;
}