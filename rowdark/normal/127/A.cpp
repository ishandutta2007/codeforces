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
long double ans;
int n,x[101],y[101],k,i;
int main(){
	cin>>n>>k;
	for(i=1;i<=n;++i) cin>>x[i]>>y[i];
	for(i=1;i<n;++i) ans+=sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
	cout<<fixed<<setprecision(18)<<ans*k/50<<endl;
	cin>>n;
	return 0;
}