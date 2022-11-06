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

char M[2011][2011];
long lu[2011],ld[2011],rl[2011],rr[2011];
long n,i,j,k,l,ans;

int main(){
	for(scanf("%ld",&n),i=1;i<=n;++i) scanf("%s",M[i]+1);
	for(i=1;i<=n;++i){
		for(j=n;j!=i;--j){
			if(lu[j]^rr[i]^(M[i][j]-48)) lu[j]^=1,rr[i]^=1,++ans;
			if(ld[i]^rl[j]^(M[j][i]-48)) ld[i]^=1,rl[j]^=1,++ans;
			}
		if(lu[i]^ld[i]^rl[i]^rr[i]^(M[i][i]-48)) ++ans;
		}
	printf("%ld\n",ans);
	scanf("%ld",&n);
	return 0;
}