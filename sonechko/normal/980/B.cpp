#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define y1 dhnfg
#define ld long double

const int N = 1e6 + 11;

char a[100][100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    if (k%2==0)
    {
        cout<<"YES"<<endl;
        for (int p=2; p<=3; p++)
        for (int d=2; d<=n/2; d++)
        if (k>0)
        {
            k-=2;
            a[p][d]='#';
            a[p][n-d+1]='#';
        }
        if (k==2)
        {
            a[2][n/2+1]='#';
            a[3][n/2+1]='#';
        }
        for (int p=1; p<=4; p++)
        {
            for (int d=1; d<=n; d++)
                if (a[p][d]=='#') cout<<'#'; else cout<<'.';
            cout<<endl;
        }
    } else
    {
        cout<<"YES"<<endl;
        for (int p=2; p<=3; p++)
        for (int d=2; d<=n/2; d++)
        if (k>1)
        {
            k-=2;
            a[p][d]='#';
            a[p][n-d+1]='#';
        }
        a[2][n/2+1]='#';
        for (int p=1; p<=4; p++)
        {
            for (int d=1; d<=n; d++)
                if (a[p][d]=='#') cout<<'#'; else cout<<'.';
            cout<<endl;
        }
    }
}