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
lint zyo(lint x,lint y,lint mo){
    lint ret=1,a=x;
    while(y>0){
    	if(y%2==1) ret=(ret*a)%mo;
    	a=(a*a)%mo;y/=2;
    }
    return ret;
}
lint zyo2(lint x,lint y,lint mo){
	if(x%mo==0) return 0;
	lint z=zyo(2,y,mo-1);
	return zyo(x,z,mo);
}
lint cal(lint k,lint l,lint r,lint p){
	if(p==2){
		if(k%2==0) return 1;return 0;
	}
	lint y=zyo2(k,l,p),z;
	if(y==1) z=zyo(2,r-l+1,p);
	else{
		lint a=(zyo2(k,r+1,p)+p-1)%p,b=(y+p-1)%p;
		z=a*zyo(b,p-2,p)%p;
		//cout<<a<<' '<<b<<' '<<z<<endl;
	}
	//cout<<a<<' '<<b<<' '<<z<<endl;
	if(k%2<1) return z;
	lint sum=r-l+1,ma=1;
	if(l<1){
		lint ze=(k+1)/2;
		while(ze%2==0){
			ze/=2;sum++;ma++;
		}
	}
	lint two=zyo(2,sum-ma,p);
	z=z*zyo(two,p-2,p)%p;
	return z;
}
int main()
{
	int t,i;lint k,l,r,p;
	cin>>t;
	rep(i,t){
		//scanf("%ld %ld %ld %ld",&k,&l,&r,&p);
		cin>>k>>l>>r>>p;
		cout<<cal(k,l,r,p)<<endl;
	}
	return 0;
}