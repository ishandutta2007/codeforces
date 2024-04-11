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
int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
int main()
{
	int a,i,out=0;
	cin>>a;
	for(i=2;i<a;i++){
		int b=a;
		while(b>0){out+=b%i;b/=i;}
	}
	int gc=gcd(out,a-2);out/=gc;
	cout<<out<<'/'<<(a-2)/gc<<endl;
	return 0;
}