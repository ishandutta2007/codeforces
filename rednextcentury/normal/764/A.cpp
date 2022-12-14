#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    int n,m,z;
    cin>>n>>m>>z;
    int lcm=1;
    while(lcm%n || lcm%m)
        lcm++;
    cout<<z/lcm<<endl;
}