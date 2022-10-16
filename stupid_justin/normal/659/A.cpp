#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    cout<<((a+b)%n+n-1)%n+1;
}