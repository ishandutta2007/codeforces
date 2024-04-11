#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long double H,L;
    cin>>H>>L;

    long double ret = (L*L-H*H)/(2*H);
    cout<<setprecision(10)<<fixed<<ret<<endl;
}