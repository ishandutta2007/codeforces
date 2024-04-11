#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define ld long double
const ll N = 1e6 + 11;
int kol[N],a[N];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int max1=0,max2=0;
    for (int i=1; i<=n; i++)
    {
        if (max1>a[i]&&max2<a[i]) kol[max1]++;
        if (max1<a[i]) kol[a[i]]--;
        if (a[i]>max1) {max2=max1; max1=a[i];} else
        if (a[i]>max2) {max2=a[i];}
    }
    int x=1;
    for (int i=1; i<=n; i++)
    {
        if (kol[i]>kol[x]) x=i;
    }
    cout<<x<<endl;
}
/**
5 1 4 2 3 6
1 - 1
4 - 1
2 - 2
3 - 2
6 - 0
**/