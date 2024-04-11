#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const int N = 10000 + 11;
int a[N],use[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        use[a[i]]=1;
    }
    for (int i=1; i<=n+1; i++)
    if (use[i]==0) {cout<<i<<endl; return 0;}
}