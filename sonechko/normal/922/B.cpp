#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for (int a=1; a<=n; a++)
    for (int b=a; b<=n; b++)
    {
        int c=a^b;
        if (c>=b&&c<=n&&a<b+c&&b<c+a&&c<a+b)
            ans++;
    }
    cout<<ans<<endl;
}