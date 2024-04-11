#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back

const int N = 1e5 + 11;

map<int,int> use;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,d;
    cin>>n>>d;
    int ans=0;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    {
        if ((i==1||a[i]-a[i-1]>=d*2)&&use[a[i]-d]==0) {ans++; use[a[i]-d]=1;}
        if ((i==n||a[i+1]-a[i]>=d*2)&&use[a[i]+d]==0) {ans++; use[a[i]+d]=1;}
    }
    cout<<ans<<endl;
}