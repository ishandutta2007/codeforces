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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
vector <lint> re,r;bool ire[110000];
template <class typ> struct BIT{
	vector<typ> x;
	BIT(int n):x(n,0){}
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
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
int rev(int a){
	int ret=0;while(a>0){ret=ret*10+a%10;a/=10;}return ret;
}
int main()
{
	BIT<int> bit(110000);lint inf=1000000000000LL,ma=inf,outx=-1,outy=-1,ny,i,j,maxx,maxy,w;
	cin>>maxx>>maxy>>w;ny=maxy;memset(ire,false,sizeof(ire));
	re.pb(0);for(i=1;i<110000;i++) re.pb(rev(i));
	for(i=1;i<re.size();i++){
		if(i==re[i]){r.pb(i);ire[i]=true;}
	}
	for(i=1;i<=maxx;i++){
		if(ire[i]){
			for(j=0;j<r.size();j++) bit.add((int)r[j],1);
		}
		else{
			int g=gcd(i,re[i]);
			for(j=1;j*re[i]/g<=maxy;j++){
				if(re[j*re[i]/g]==j*i/g) bit.add((int)(j*re[i]/g),1);
			}
		}
		while(bit.sum(0,ny-1)>=w) ny--;//cout<<ny<<' '<<bit.sum(0,ny)<<endl;
		if(bit.sum(0,ny)>=w && i*ny<=ma){ma=i*ny;outx=i;outy=ny;}
	}
	if(ma>=inf) cout<<"-1"<<endl;else cout<<outx<<' '<<outy<<endl;
	return 0;
}