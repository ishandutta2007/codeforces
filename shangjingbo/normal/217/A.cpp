#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

const int maxn  =   105;

int x[maxn],y[maxn],n,father[maxn];

int Find(int x)
{
    return father[x]==x?x:father[x]=Find(father[x]);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d%d",&x[i],&y[i]);
        father[i]=i;
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (x[i]==x[j] || y[i]==y[j]) father[Find(i)]=Find(j);
        }
    }
    int cnt=0;
    for (int i=0;i<n;++i){
        cnt+=Find(i)==i;
    }
    printf("%d\n",cnt-1);
    return 0;
}