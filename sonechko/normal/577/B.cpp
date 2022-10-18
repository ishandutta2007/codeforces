#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

int a[N],use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int j=1; j<=n; j++)
    cin>>a[j];
    if (n>m) {cout<<"YES"<<endl; return 0;}
    use[a[1]%m]=1;
    for (int j=2; j<=n; j++)
    {
        a[j]%=m;
        for (int p=m-1; p>=0; p--)
            if (use[p]==1) use[p+a[j]]=1;
        for (int p=m; p<=m*2; p++)
            if (use[p]) use[p%m]=1;
        use[a[j]%m]=1;
    }
    if (use[0]==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}