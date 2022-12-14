#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int a[3];
    int d;
    cin>>a[0]>>a[1]>>a[2]>>d;
    sort(a,a+3);
    cout<<max(0,d-a[2]+a[1])+max(0,d-a[1]+a[0])<<endl;
}