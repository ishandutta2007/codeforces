#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e6 + 11;
const int MOD = 998244353;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int ii=1; ii<=t; ii++)
    {
          int p;
          cin>>p;
          string s;
          cin>>s;
          int n=s.size();
          s="."+s;
          int ans=1;
          for (int i=1; i<=n; i++)
          {
                char ch1=s[i],ch2=s[n-i+1];
                int p1=ch1-'a',p2=ch2-'a';
                //cout<<p1<<" "<<p2<<endl;
                //cout<<ch1<<" "<<ch2<<endl;
                if (abs(p1-p2)>2||abs(p1-p2)==1) ans=0;
          }
          if (ans==1) cout<<"YES\n"; else cout<<"NO\n";
    }
}