#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 2e5 + 11;

pair<int,int> b[N];
int a[N],ans[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
        {
            cin>>a[i];
        }
    for (int i=1; i<=m; i++)
        {
            cin>>b[i].ff;
            b[i].ss=i;
            }
    sort(a+1,a+m+1);
    sort(b+1,b+m+1);
    for (int i=1; i<=m; i++)
    {
        int l=m-i+1;
        ans[b[i].ss]=a[l];
    }
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}