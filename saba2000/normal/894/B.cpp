#include<iostream>
#define l long long
#define r return
#define c cout<<
using namespace std;
l m=1e9+7,n,k,p;
l e(l x,l N)
{if(!N) r 1; if(N&1) r x*e(x,N-1)%m;else r e(x*x%m,N/2)%m; }
main()
{   cin>>n>>p>>k;
    if(k-1 && (n+p)&1) c 0;
    else c e(e(2,n-1),p-1); }