#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 100 + 11;
const int MOD = 998244353;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y,z;
    cin>>x>>y>>z;
    int p1=x-y-z;
    int p2=x-y+z;
    if (p2<0) cout<<"-"; else
    if (p1>0) cout<<"+"; else
    if (p1==0&&p2==0) cout<<"0"; else cout<<"?";
}