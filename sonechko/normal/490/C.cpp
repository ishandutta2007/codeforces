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
int use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k1,k2;
    cin>>k1>>k2;
    int n=s.size();
    s='.'+s;
    int d=0;
    for (int i=1; i<=n; i++)
    {
        int k=s[i]-'0';
        d=(d*10+k)%k1;
        if (d==0) use[i]=1;
    }
    int dd=1;
    d=0;
    for (int i=n; i>=1; i--)
    {
        int k=s[i]-'0';
        if (i!=n) dd=(dd*10)%k2;
        d=(d+dd*k)%k2;
        if (d==0&&use[i-1]==1&&k!=0)
        {
            cout<<"YES"<<endl;
            for (int j=1; j<i; j++)
                cout<<s[j];
            cout<<endl;
            for (int j=i; j<=n; j++)
                cout<<s[j];
            cout<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}