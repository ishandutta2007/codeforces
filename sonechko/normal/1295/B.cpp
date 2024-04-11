#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back

const int N = 2e5 + 11;

int dp[N];

void up()
{
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    int bal=0,t=0;
    if (x==0) t=1;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='0') bal++; else bal--;
        if (bal==x) t=1;
    }
    if (t==1&&bal==0) {cout<<"-1\n"; return;}
    if (bal==0) {cout<<"0\n"; return;}
    int bal2=0;
    ll ans=0;
    if (x==0) ans++;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='0') bal2++; else bal2--;
        int t=(x-bal2);
        ///cout<<t<<" "<<bal<<endl;
        if ((t<=0&&bal<0)||(t>=0&&bal>0))
        {
            if ((abs(t)%abs(bal))==0) ans++;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}