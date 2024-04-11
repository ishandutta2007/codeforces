#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define pll pair<ll,ll>
using namespace std;
int main()
{
ll n;
cin>>n;
if(n==1)
cout<<1<<" "<<1<<endl<<1;
else
cout<<(n-1)*2<<" "<<2<<endl<<1<<" "<<2;
}