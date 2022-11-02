// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
struct R {
    LL x1,y1,x2,y2;
    void read() {
        cin>>x1>>y1>>x2>>y2;
    }
    LL area() {
        return (x2-x1)*(y2-y1);
    }
    void ext( R p ) {
        x1=min(x1,p.x1);
        x2=max(x2,p.x2);
        y1=min(y1,p.y1);
        y2=max(y2,p.y2);
    }
} r[5],rr;
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) r[i].read();
    rr=r[0];
    for ( int i=1; i<n; i++ ) rr.ext(r[i]);
    LL aa=rr.area(),a=0;
    for ( int i=0; i<n; i++ ) a+=r[i].area();
    cout<<((rr.x2-rr.x1==rr.y2-rr.y1&&a==aa)?"YES":"NO")<<endl;
    return 0;
}