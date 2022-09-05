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
    ll x,y,n;
    cin>>n>>x>>y;
    if (y<n) {cout<<"-1";return 0;}
    if ((y-n+1)*(y-n+1)+n-1<x) {cout<<"-1"; /*system("pause");*/return 0;}
    cout<<y-n+1<<endl;
    FOR(i,0,n-1)
    cout<<1<<endl;
    return 0;
}