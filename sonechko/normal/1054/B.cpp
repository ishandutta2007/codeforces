#include<bits/stdc++.h>
using namespace std;

#define ff first
#define pb push_back
#define ss second
#define mp make_pair
#define ll long long
#define mod %MOD

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int a[N];
bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int pos=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (l>pos) {cout<<i<<endl; return 0;}
        use[l]=1;
        while (use[pos]==1)
            pos++;
    }
    cout<<-1<<endl;
}