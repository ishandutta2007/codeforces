#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
const int N=1000005;
long long a[N];
int main(){
    a[0]=0;
    for(long long i=1;i<N;i++){
        a[i]=i*(i-1)/2;
    }
    cin>>n>>m;
    long long Min=max((long long)0,n-2*m);
    long long k=lower_bound(a,a+n,m)-a;
    long long Max=n-k;
    cout<<Min<<" "<<Max<<endl;
    return 0;
}