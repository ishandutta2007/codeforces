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
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

long long n,A,B,C,D,ans=0,c1,c2,b,c;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	if (n%3){
		puts("0");
		return 0;
	}
	n/=3;
	
	for (long long s=2;s*s*s<=n*6;s++)if (n%s==0){
		for (long long a=1;a+a<=s;a++){
			A=1;
			B=s;
			C=-a*a+s*a-n/s;
			D=B*B-4*C;
			long long sq=sqrt(D);
			if (sq*sq!=D)continue;
			c1=(-B-sq)/2;
			c2=(-B+sq)/2;
			if ((-B-sq)%2)continue;
			if ((-B+sq)%2)continue;
			if (c1<=0&&c2<=0)continue;
			if (c1<0)c1=c2;
			b=s-a;
			c=c1;
			if (a>b||b>c)continue;
			if (a==b&&b==c)ans++;else
			if (a==b)ans+=3;else if (b==c)ans+=3;else ans+=6;
		}
	}
	cout << ans<< endl;
	return 0;
}