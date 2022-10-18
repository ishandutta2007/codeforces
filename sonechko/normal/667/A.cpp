#include<bits/stdc++.h>
using namespace std;
#define ld long double
int main()
{
    ld d,h,v,e;
    cin>>d>>h>>v>>e;
    ld pp=v/(M_PI*d*d/4);
    cout.precision(10);
    cout<<fixed;
    if (pp>e) {cout<<"YES"<<endl; cout<<h/(v*4/M_PI/d/d-e)<<endl;}
    else cout<<"NO"<<endl;
}