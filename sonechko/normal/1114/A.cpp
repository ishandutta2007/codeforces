#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z,a,b,c;
    cin>>x>>y>>z>>a>>b>>c;
    if (x>a) {cout<<"NO"; return 0;}
    a-=x;
    if (y>a+b) {cout<<"NO"; return 0;}
    if (z>c+a+b-y) {cout<<"NO"; return 0;}
    cout<<"YES";
}