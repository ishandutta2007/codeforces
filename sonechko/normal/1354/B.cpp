#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

void up()
{
    string s;
    cin>>s;
    int l1=-1,l2=-1,l3=-1;
    int ans=2e9;
    for (int j=0; j<s.size(); j++)
    {
        if (s[j]=='1') l1=j; else
        if (s[j]=='2') l2=j; else l3=j;
        if (l1!=-1&&l2!=-1&&l3!=-1)
            ans=min(ans,j-min({l1,l2,l3})+1);
    }
    if (ans==2e9) cout<<0<<"\n"; else cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}