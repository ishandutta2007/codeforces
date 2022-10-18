#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    n%=4;
    char c=a,d=a;
    for (int i=1; i<=n; i++)
    {
        if (c=='^') c='>'; else
        if (c=='>') c='v'; else
        if (c=='v') c='<'; else  c='^';
        if (d=='^') d='<'; else
        if (d=='>') d='^'; else
        if (d=='v') d='>'; else  d='v';
    }
    if (c==b&&d!=b) cout<<"cw"; else
    if (c!=b&&d==b) cout<<"ccw"; else cout<<"undefined";
}