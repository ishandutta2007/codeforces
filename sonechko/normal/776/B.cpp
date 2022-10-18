#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    n++;
    use[1]=1;
    for (int i=2; i<=n; i++)
        if (use[i]==0)
    {
        for (int j=i+i; j<=n; j+=i)
            use[j]=1;
    }
    if (n<=3) cout<<1<<endl; else cout<<2<<endl;
    for (int i=2; i<=n; i++)
        cout<<use[i]+1<<" ";
}