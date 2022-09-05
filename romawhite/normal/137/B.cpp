#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n,m=0,k,l;
    cin>>n;
    int a[5001];
    memset(a,0,sizeof(a));
    FOR(i,0,n)
    {
        cin>>k;
        a[k]++;
    }
    FOR(i,1,n+1)
        if (a[i]>0) m++;
    cout<<n-m;
    return 0;
}