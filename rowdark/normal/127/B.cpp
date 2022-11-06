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

long a[101],n,i,j;
long ans;

int main(){
	cin>>n;
	for(i=1;i<=n;++i) cin>>j,++a[j];
	for(j=-1,i=100;i;--i) while(a[i]>1) {a[i]-=2;if(j==-1) j=i;else ++ans,j=-1;}
	cout<<ans<<endl;
	cin>>n;
	return 0;
}