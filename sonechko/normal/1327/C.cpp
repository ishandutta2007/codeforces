#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=k*2; i++)
    {
        int l,r;
        cin>>l>>r;
    }
    cout<<(n-1)+(m-1)+(n*m-1)<<"\n";
    for (int i=1; i<=n-1; i++)
        cout<<"U";
    for (int i=1; i<=m-1; i++)
        cout<<"L";
    int l=1,r=1;
    while (1)
    {
        if (l%2==1&&l==n&&r==m) break;
        if (l%2==0&&l==n&&r==1) break;
        if (l%2==1&&r==m) {l++; cout<<"D";} else
        if (l%2==0&&r==1) {l++; cout<<"D";} else
        if (l%2==1) {r++; cout<<"R";} else {r--; cout<<"L";}
    }
}
/**

**/