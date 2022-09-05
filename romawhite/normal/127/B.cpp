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
    int n,k;
    cin>>n;
    int a[200];
    FOR(i,0,200)
        a[i]=0;
    FOR(i,0,n)
    {
        cin>>k;
        a[k]++;
    }
    int s=0;
    FOR (i,0,200)
        s+=a[i]/2;
    s/=2;
    cout<<s;
    return 0;
}