#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;
const int N = 500001;
const int M = 10;
const string st2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string s1 = "abcdefghijklmnopqrstuvwxyz";
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define filestxt freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
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
ll a1[N],c1,a2[N],c2,sum1,sum2,n1,n2;
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            ll l;
            cin>>l;
            if (l>0) {sum1+=l; if (i>c1) c1=i; n1++; a1[n1]=l;} else
            {
                sum2+=abs(l);
                if (i>c2) c2=i;
                n2++;
                a2[n2]=abs(l);
            }
        }
    if (sum1>sum2) cout<<"first"<<endl; else
    if (sum2>sum1) cout<<"second"<<endl; else
    {
        for (int i=1; i<=min(n1,n2); i++)
        if (a1[i]>a2[i]) {cout<<"first"<<endl; return 0;} else
        if (a2[i]>a1[i]) {cout<<"second"<<endl; return 0;}
        if (n1>n2) cout<<"first"<<endl; else
        if (n2>n1) cout<<"second"<<endl; else
        if (c1>c2) cout<<"first"<<endl; else cout<<"second"<<endl;
    }
}