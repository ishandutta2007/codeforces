#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;

int gcd(int a,int b){
    if (b==0 && a!= 1) return 1000000000;
    if (b==0) return -1;
    return a/b+gcd(b,a%b);
}

int main(){
    int n,m=1000000000;
    cin>>n;
    if (n==1) {cout<<'0';return 0;}
    FOR(i,1,n)
        m=min(m,gcd(n,i));
    cout<<m;
    return 0;
}