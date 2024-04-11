#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ull unsigned long long
#define mp make_pair
#define pb push_back



const int N = 1e5 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a=1,b=n;
    for (int i=1; i<=n; i++)
    {
        int p=n-i;
        int d=__gcd(i,p);
        if (d==1&&i<p)
        {
            if (a*p-b*i<0) {a=i; b=p;}
        }
    }
    cout<<a<<" "<<b<<endl;
}