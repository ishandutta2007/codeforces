#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define mp make_pair
const ll N = 100000 + 11;

int a[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    a[1]=1;
    a[2]=1;
    use[1]=1;
    for (int i=3; i<=1000; i++)
    {
        a[i]=a[i-1]+a[i-2];
        if (a[i]>n) break;
        use[a[i]]=1;
    }
    for (int i=1; i<=n; i++)
        if (use[i]==1) cout<<'O'; else cout<<'o';
}