#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    if (n%3==0) cout<<1<<" "<<1<<" "<<n-2<<endl; else
    if (n%3==1) cout<<1<<" "<<1<<" "<<n-2<<endl; else
    if (n%3==2) cout<<1<<" "<<2<<" "<<n-3<<endl;
}