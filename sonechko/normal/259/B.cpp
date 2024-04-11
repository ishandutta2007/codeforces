#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 20001;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, sizeof(x), y)
#define sqr(a) ((a) * (a))
#define endl "\n"
#define ld long double
#define outld(l) cout.precision(l);cout << fixed
#define s second
#define ll long long
#define f first
#define mp make_pair
int a[4][4],b[4];
int main()
{
    for (int i=1; i<=3; i++)
        for (int j=1; j<=3; j++)
        {
            cin>>a[i][j];
            b[i]+=a[i][j];
        }
    for (int p=100000; p>=0; p--)
    {
        int k=b[1]+p;
        a[1][1]=p;
        a[2][2]=k-b[2];
        a[3][3]=k-b[3];
        if (a[2][2]>0&&a[3][3]>0&&a[1][1]+a[2][2]+a[3][3]==k&&
            a[1][3]+a[2][2]+a[3][1]==k)
        {
            for (int i=1; i<=3; i++)
            {
                for (int j=1; j<=3; j++)
                    cout<<a[i][j]<<" ";
                cout<<endl;
            }
            return 0;
        }
    }
}