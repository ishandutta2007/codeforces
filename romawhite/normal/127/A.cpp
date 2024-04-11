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
double d(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    int n,k;
    cin>>n>>k;
    double x[200],y[200];
    double l,s,a;
    FOR(i,0,n)
        cin>>x[i]>>y[i];
    l=0;
    FOR(i,1,n)
        l+=d(x[i],y[i],x[i-1],y[i-1]);
    a=(l*k)/50;
    printf("%0.10f",a);
    return 0;
}