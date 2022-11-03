#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <numeric>
#include <list>
#include <unordered_set>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x3f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x3f3f3f3f)
#define INF ((long long)0x3f3f3f3f3f3f3f3f)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(...) return printf(__VA_ARGS__),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) (((a)>>(b))&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
#define reg register
#define prtime eprintf("\n\nTime used: %dms\n",clock());
#define PI 3.1415926535897932384626
#define TODEG(a) (a*180/PI)
#define y0 ykangjimutigeidiqiuyipianjingtu
#define y1 yxiaomiexuduhuanrenleiwannianankang
#define endl '\n'
#define left leftxiaomiexudurenrenyouze
#define hash hashxushibingduyouweilifushiyiqiedewuti
using namespace std;

char s[500005],t[500005];
int cnts[2],cntt[2];
unordered_set<long long> haa;

int main(){
	scanf("%s",s);
	scanf("%s",t);
	int n=strlen(s),m=strlen(t);
	long long num=1,num2=0;
	long long num11=1,num22=0;
	for(int i=0;i<n;i++){
		cnts[s[i]-'0']++;
	}
	for(int i=0;i<m;i++){
		cntt[t[i]-'0']++;
	}
	for(int i=m-1;i>=0;i--){
		num2=(num2+num*(t[i]-'0'+1))%1000000007;
		num22=(num22+num11*(t[i]-'0'+1))%19260817;
		haa.insert(num2*19260817LL+num22);
		num=num*5%1000000007;
		num11=num11*3%19260817;
	}
	int mxx=0;
	num2=num22=0;
	for(int i=0;i<m-1;i++){
		num2=(num2*5+t[i]-'0'+1)%1000000007;
		num22=(num22*3+t[i]-'0'+1)%19260817;
		if(haa.count(num2*19260817LL+num22)){
			mxx=i+1;
		}
	}
	for(int i=0;i<mxx;i++){
		if(!cnts[t[i]-'0']){
			goto shit;
		}
		cnts[t[i]-'0']--;
		cntt[t[i]-'0']--;
		printf("%c",t[i]);
	}
	while(1){
		if(cntt[0]>cnts[0]||cntt[1]>cnts[1]){
			break;
		}
		printf("%s",t+mxx);
		cnts[0]-=cntt[0];
		cnts[1]-=cntt[1];
	}
	shit:;
	for(int i=0;i<cnts[0];i++){
		printf("0");
	}
	for(int i=0;i<cnts[1];i++){
		printf("1");
	}
	return 0;
}