#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n, m, a;
    scanf("%d %d %d",&n,&m,&a);
    cout<<(((n+a-1)/a)*1LL*((m+a-1)/a))<<endl;
    return 0;
}