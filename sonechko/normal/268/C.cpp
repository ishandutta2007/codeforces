#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<min(n,m)+1<<endl;
    for (int i=0; i<=min(n,m); i++)
        cout<<i<<" "<<min(n,m)-i<<endl;
}