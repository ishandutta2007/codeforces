#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e5 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a1,b1,a2,b2,x,y;
    cin>>a1>>b1>>a2>>b2>>x>>y;
    if (abs(a1-a2)%x==0&&abs(b1-b2)%y==0
        &&abs(a1-a2)/x%2==abs(b1-b2)/y%2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}