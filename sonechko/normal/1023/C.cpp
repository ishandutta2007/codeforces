#include<bits/stdc++.h>
using namespace std;

#define y1 ojf
#define ld long double
#define ull unsigned long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


const int N = 3e5 + 11;

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v;
    s="."+s;
    int d=(n-k)/2;
    for (int i=1; i<=n; i++)
        if (s[i]=='(') v.pb(i); else
    {
        int l=v.back();
        v.pop_back();
        if (d>0)
        {
            d--;
            use[l]=1;
            use[i]=1;
        }
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0) cout<<s[i];
    cout<<endl;
}