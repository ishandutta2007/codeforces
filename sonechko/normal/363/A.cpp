#include<bits/stdc++.h>

const long long MOD = 1e9 + 7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define ll unsigned long long
#define endl "\n"

using namespace std;

void good(int l)
{
    if (l>=5)
    {
        l-=5;
        cout<<"-O|";
    } else
    {
        cout<<"O-|";
    }
    int k=0;
    while (l>0)
    {
        l--;
        cout<<"O";
        k++;

    }
    k++;
    cout<<"-";
    while (k<5)
    {
        cout<<"O";
        k++;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    if (n==0) good(0);
    while (n>0)
    {
        good(n%10);
        n=n/10;
    }
}