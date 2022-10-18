#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;

int use[5][10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        for (int k=1; k<=6; k++)
        {
            int l;
            cin>>l;
            use[i][l]=1;
        }
    }
    if (n==1)
    {
        int ans=0;
        for (int p=1; p<=9; p++)
            if (use[1][p]==0)
        {
            break;
        } else ans=p;
        cout<<ans<<endl;
        return 0;
    }
    if (n==2)
    {
        int ans=0;
        for (int p=1; p<=9; p++)
            if (use[1][p]+use[2][p]==0)
        {
            cout<<ans<<endl;
            return 0;
        } else ans=p;
        for (int p=10; p<=99; p++)
            if (use[1][p/10]+use[2][p%10]!=2&&use[2][p/10]+use[1][p%10]!=2)
        {
            cout<<ans<<endl;
            return 0;
        } else ans=p;
    }
     int ans=0;
        for (int p=1; p<=9; p++)
            if (use[1][p]+use[2][p]+use[3][p]==0)
        {
            cout<<ans<<endl;
            return 0;
        } else ans=p;
        for (int p=10; p<=99; p++)
            if (use[1][p/10]+use[2][p%10]!=2&&
                use[1][p/10]+use[3][p%10]!=2&&
                use[2][p/10]+use[1][p%10]!=2&&
                use[2][p/10]+use[3][p%10]!=2&&
                use[3][p/10]+use[1][p%10]!=2&&
                use[3][p/10]+use[2][p%10]!=2
                )
        {
            cout<<ans<<endl;
            return 0;
        } else ans=p;
        for (int p=100; p<=999; p++)
        {
            int x=p/100;
            int y=p/10%10;
            int z=p%10;
        if (use[1][x]+use[2][y]+use[3][z]!=3&&
            use[1][x]+use[2][z]+use[3][y]!=3&&
            use[1][y]+use[2][x]+use[3][z]!=3&&
            use[1][y]+use[2][z]+use[3][x]!=3&&
            use[1][z]+use[2][x]+use[3][y]!=3&&
            use[1][z]+use[2][y]+use[3][x]!=3)
            {cout<<ans<<endl; return 0;}
            else ans=p;
        }
}