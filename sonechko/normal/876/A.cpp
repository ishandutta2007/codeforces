#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define ull unsigned long long
#define pb push_back
#define ld long double

const int N = 1000000 + 11;
const int MAX = 1e8;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int k=1,ans=0;
    for (int i=1; i<n; i++)
    {
        if (k==1&&a<b) {ans+=a; k=2;} else
        if (k==1) {ans+=b; k=3;} else
        if (k==2&&a<c) {ans+=a; k=1;} else
        if (k==2) {ans+=c; k=3;} else
        if (b<c) {ans+=b; k=1;} else
        {
            ans+=c;
            k=2;
        }
    }
    cout<<ans<<endl;
}