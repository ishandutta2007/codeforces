#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
#define mod % MOD
#define filesio(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout)
#define filesds(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout)
#define filestt(x) freopen(x ".txt", "r", stdin); freopen(x ".txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define int1 long long
#define endl "\n"

int main()
{
    int1 l=0,r=0,k=0;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='^')
        {
            int1 p=0;
            for (int1 j=i-1; j>-1; j--)
            {
                p++;
                int1 k;
                if (s[j]=='=') k=0; else
                    k=s[j]-'0';
                l+=p*k;
            }
            p=0;
            for (int1 j=i+1; j<s.size(); j++)
            {
                p++;
                int1 k;
                if (s[j]=='=') k=0; else
                    k=s[j]-'0';
                r+=p*k;
            }
        }
    }
    if (l==r) cout<<"balance"<<endl; else
    if (l>r) cout<<"left"<<endl; else
    cout<<"right"<<endl;
}