#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back
const int N = 1e5 + 11;
int dp[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int d=1; d<=n; d++)
    {
        int l;
        cin>>l;
        if (l==1||l==2||l==3||l==5||l==7||l==11)
            cout<<-1<<"\n"; else
        if (l==4||l==6||l==9) cout<<1<<"\n"; else
        if (l==8||l==10) cout<<2<<"\n"; else
        if (l%4==0||l%4==2) cout<<l/4<<"\n"; else
        cout<<l/4-1<<"\n";
    }
    cout<<endl;
}