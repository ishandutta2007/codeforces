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
#define P 1000000007

const double pi = 3.1415926535;
const double eps = 1e-4;

long dp[1001][1001],i,j,k,l,n,m,p;
long sum[1001][1001];

int main(){
	for(i=1;i<1001;++i) dp[0][i]=1,sum[0][i]=sum[0][i-1]+1;
	for(i=1;i<1001;++i)
		for(j=i*2+1;j<1001;++j){
			if(P<=(dp[i][j]=dp[i][j-1]+sum[i-1][j-2])) dp[i][j]-=P;
			if(P<=(sum[i][j]=dp[i][j]+sum[i][j-1])) sum[i][j]-=P;
			}
	cin>>n>>m>>p;
	cout<<(long long)dp[p][n]*dp[p][m]%P<<endl;
	cin>>n;
	return 0;
}