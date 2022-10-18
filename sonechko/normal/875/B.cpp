#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    cout<<1<<" ";
    int pos=n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        use[l]=1;
        while (use[pos]==1)
            pos--;
        int kol=n-pos;
        cout<<i-kol+1<<" ";
    }
    cout<<endl;
}