#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sz size
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << x << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long ull;

int a1,b1,a2,b2,o,k=0,e[5555],ee[5555],kk=0,d1,d2;
long double ans=0,v1,v2;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a1 >> b1 >> a2 >> b2 >> o;
	for (int i=1;i<10;i++)for (int j=0;j<pw(i);j++){
		int x=0;
		for (int t=0;t<i;t++)if (j&pw(t))x=x*10+7;else x=x*10+4;
		e[k++]=x;
	}
	sort(e,e+k);
	e[k]=2000000000;
	for (int i=0;i<k;i++)if (i+o<=k){
		if (!i)d1=min(b1,e[i])-a1+1;else d1=min(b1,e[i])-max(a1-1,e[i-1]);
		d2=min(b2,e[i+o]-1)-max(e[i+o-1],a2)+1;
		v1=d1/1./(b1-a1+1);
		v2=d2/1./(b2-a2+1);
		if (v1<0||v2<0)continue;
		ans+=v1*v2;
	}
	for (int i=0;i<k;i++)if (i+o<=k){
		if (!i)d1=min(b2,e[i])-a2+1;else d1=min(b2,e[i])-max(a2-1,e[i-1]);
		d2=min(b1,e[i+o]-1)-max(e[i+o-1],a1)+1;
		v1=d1/1./(b2-a2+1);
		v2=d2/1./(b1-a1+1);
		if (v1<0||v2<0)continue;
		if (o==1&&e[i]>=a1&&e[i]<=b1&&e[i]>=a2&&e[i]<=b2)ans-=1./(b2-a2+1)/(b1-a1+1);
		ans+=v1*v2;
	}
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}