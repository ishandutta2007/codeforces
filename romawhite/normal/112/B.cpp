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
    if ((x!=n/2 && x!=n/2+1) || (y!=n/2 && y!=n/2+1)) cout<<"YES";else cout<<"NO";
    return 0;
}