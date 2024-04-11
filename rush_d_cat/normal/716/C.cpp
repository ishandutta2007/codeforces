#include <iostream>
#include <cmath>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false)
#define INF 1e18
#define MOD 1e9 + 7
#define MAXN 50000+10
#define MAXM 500000+10
char s[MAXN];
int cnt[30];
int main()
{
    ll n;cin>>n;
    for(ll i=1;i<=n;i++){
        if(i==1) cout<<2<<endl;
        if(i==2) cout<<17<<endl;
        if(i>=3) cout<<(i*i*i+2*i*i+1)<<endl;
    }
}