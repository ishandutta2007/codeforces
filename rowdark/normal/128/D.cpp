#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
typedef pair<long,long> pii;

const double pi = 3.1415926535;
const double eps = 1e-4;

pii P[100005];
long n,i,j,k,l;

inline bool check(){
	for(i=2;i<=n;++i) if(P[i].first!=P[i-1].first+1) return 0;
	for(i=2;i<n;++i) if(P[i].second<2) return 0;
	for(i=2;i<=n;++i) if(P[i].second<P[i-1].second||!P[i-1].second) return 0;else P[i].second-=P[i-1].second;
	return P[n].second==0;
}

int main(){
	scanf("%ld",&n);
	for(i=1;i<=n;++i) scanf("%ld",&P[i].first);
	sort(P+1,P+n+1);
	for(P[1].second=1,j=1,i=2;i<=n;++i) if(P[i].first==P[j].first) ++P[j].second;else P[++j]=P[i],P[j].second=1;
	n=j;
	printf("%s\n",check()?"YES":"NO");
	scanf("%ld",&n);
	return 0;
}