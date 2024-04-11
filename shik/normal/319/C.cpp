// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long double LL;
#define j q.front()
#define k q.back()
#define N 100010
int n,a[N],b[N];
LL f[N],t[N];
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<=n; i++ ) scanf("%d",b+i);
    deque<int> q;
    q.push_back(1);
    for ( int i=2; i<=n; i++ ) {
        while ( q.size()>1 && a[i]>t[q[1]] ) q.pop_front();
        f[i]=f[j]+(LL)b[j]*a[i];
        while ( !q.empty() && (LL)(f[i]-f[k])/(b[k]-b[i])<=t[k] ) q.pop_back();
        if ( q.empty() ) t[i]=0;
        else t[i]=(LL)(f[i]-f[k])/(b[k]-b[i]);
        q.push_back(i);
    }
    cout<<(long long)(f[n]+0.5)<<endl;
    return 0;
}