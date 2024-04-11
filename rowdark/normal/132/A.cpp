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
int F[300],G[1001];
char S[1001];
int i,j,k,l;

int main(){
    for(i=1;i<256;++i) F[i]=F[i^(i&-i)]+128/(i&-i);
    gets(S+1);
    l=strlen(S+1);
    for(i=1;i<=l;++i) G[i]=F[S[i]];
    for(i=1;i<=l;++i) printf("%d\n",G[i-1]-G[i]<0?G[i-1]-G[i]+256:G[i-1]-G[i]);
    return 0;
}