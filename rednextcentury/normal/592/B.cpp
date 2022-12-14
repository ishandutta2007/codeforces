#include<bits/stdc++.h>
using namespace std;
char mp[10][10];
int main()
{
    long long n;
    cin>>n;
    if (n==3)
        cout<<1<<endl;
    else
        cout<<1+ 3*(n-3)+(n-3)*(n-4)<<endl;
}