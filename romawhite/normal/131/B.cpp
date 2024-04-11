#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n,k,l,m;
    ll a[50];
    FOR(i,0,40)
    a[i]=0;
    cin>>n;
    FOR(i,0,n){
               cin>>k;
               a[k+10]++;
               }
    ll res=0;
    FOR(i,0,10)
    res+=a[i]*a[20-i];
    res+=(a[10]-1)*a[10]/2;
    cout<<res;
    return 0;
}