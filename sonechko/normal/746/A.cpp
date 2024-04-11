#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
int use[N];
int main()
{
    sync;
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    for (int i=0; i<=a; i++)
    if (i*2<=b&&i*4<=c) ans=i+i*2+i*4;
    cout<<ans<<endl;
}