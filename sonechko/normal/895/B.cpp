#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

const int N = 1e5 + 11;
int a[N];
map<int,int> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x,k;
    cin>>n>>x>>k;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    ll ans=0;
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    {
        int d=a[i]/x;
        ans+=1LL*mt[d-k];
        mt[(a[i]-1)/x]++;
    }
    mt.clear();
    for (int i=1; i<=n; i++)
    {
        mt[a[i]]++;
        if (a[i]%x==0&&k==1) ans+=1LL*mt[a[i]];
        if (a[i]%x!=0&&k==0) ans+=1LL*mt[a[i]];
    }
    cout<<ans<<endl;
}
/**
 
4 2 1
1 3 5 7
 
3
 
4 2 0
5 3 1 7
 
4
 
5 3 1
3 3 3 3 3
 
25
**/