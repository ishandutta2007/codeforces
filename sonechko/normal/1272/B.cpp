#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

void up()
{
    string s;
    cin>>s;
    int l1=0,r1=0,u1=0,d1=0;
    for (int j=0; j<s.size(); j++)
    {
        char c=s[j];
        if (c=='L') l1++;
        if (c=='R') r1++;
        if (c=='U') u1++;
        if (c=='D') d1++;
    }
    int x=min(l1,r1);
    int y=min(u1,d1);
    if (x>0&&y>0)
    {
        cout<<x*2+y*2<<"\n";
    for (int i=1; i<=x; i++)
        cout<<"L";
    for (int i=1; i<=y; i++)
        cout<<"U";
    for (int i=1; i<=x; i++)
        cout<<"R";
    for (int i=1; i<=y; i++)
        cout<<"D";
    cout<<"\n";
    } else
    {
        if (x>0) cout<<"2\nLR\n"; else
        if (y>0) cout<<"2\nUD\n"; else cout<<"0\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
        up();
}

/**

**/