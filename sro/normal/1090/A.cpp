/*----------------by syr----------------*/
/*
  -----  -----  -----
  |   |  |---|    _/
  |   |  | \_    /
  -----  |   \  -----

  |---\  \   /  |\  /|
  |   |   \_/   | \/ |
  |   |   / \   |    |
  |---/  /   \  |    |
*/
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<limits>
#include<list>
#include<map>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;

const int INF=1e9+7;
const int maxn=2e5+5;

int n;
ll totMx,ans=0;
ll mx[maxn];
vector<ll> a[maxn];

int main(){
	scanf("%d",&n);
	FOR(i,0,n){
		a[i].resize(1);
		scanf("%I64d",&a[i][0]);
		a[i].resize(a[i][0]+1);
		REP(j,1,a[i][0]){
			scanf("%I64d",&a[i][j]);
			mx[i]=max(a[i][j],mx[i]);
		}
	}
	FOR(i,0,n) totMx=max(totMx,mx[i]);
	FOR(i,0,n) ans+=(totMx-mx[i])*a[i][0];
	printf("%I64d\n",ans);
	return 0;
}