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
int out[512810];
int main()
{
	int x,y,z,w,n;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d %d %d %d",&x,&y,&z,&w);
		int ret=1;
		if(x%2==0) ret+=1;
		if(y%2==0) ret+=2;
		out[i]=ret;
	}
	printf("YES\n");
	rep(i,n) printf("%d\n",out[i]);
}