#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 2e6 + 11;
int use[N],a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        use[a[i]]=1;
    }
    for (int j=1; j<=n; j++)
    {
        cin>>b[j];
        use[b[j]]=1;
    }
    int kol=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        int d=a[i]^b[j];
        if (d<=2000000&&use[d]==1) kol++;
    }
    if (kol%2==0) cout<<"Karen"<<endl;
    else cout<<"Koyomi"<<endl;
}