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
    string s;
    cin>>s;
    int a[s.size()][s.size()];
    ms(a,0);
    if (s.size()<4) {cout<<0<<endl; return 0;}
    for (int i=0; i<s.size(); i++)
     for (int j=i+3; j<s.size(); j++)
      {
          a[i][j]=a[i][j-1];
          if (s[j]=='r'&&s[j-1]=='a'&&s[j-2]=='e'&&s[j-3]=='b'&&a[i][j]==0)
            a[i][j]++;
      }
    int ans=0;
    for (int i=0; i<s.size(); i++)
        for (int j=i; j<s.size(); j++)
        ans+=a[i][j];
    cout<<ans<<endl;
}