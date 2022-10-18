#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int P1 = 31;
const int P2 = 29;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int get(int kol, int d)
{
    return (kol+d-1)/d;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        if ((abs(x-y))%d==0) cout<<(abs(x-y))/d<<"\n"; else
        {
            int c=get(n-x,d);
            int p=get(x-1,d);
            int ans=2e9;
            if ((n-y)%d==0) ans=min(ans,(n-y)/d+c);
            if ((y-1)%d==0) ans=min(ans,(y-1)/d+p);
            if (ans==(int)2e9) cout<<-1<<"\n"; else cout<<ans<<"\n";
        }
    }
}
/**
d=3
1 - 0
2 - 1
3 - 1
4 - 1
5 - 2
**/