#include<bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    if (n==0) cout<<1<<endl; else
    if (n%4==1) cout<<8<<endl; else
    if (n%4==2) cout<<4<<endl; else
    if (n%4==3) cout<<2<<endl; else cout<<6<<endl;
}