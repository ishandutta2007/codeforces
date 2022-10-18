#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

vector<int> vv;
int n;
int use[N];

bool rec(int l, int kol)
{
    if (l==vv.size())
    {
        for (int p=1; p<=kol; p++)
        {
            int d=0;
            for (int x=0; x<vv.size(); x++)
                if (use[x]==p) d+=vv[x];
            if (d>n) return false;
        }
        return true;
    }
    for (int g=1; g<=kol; g++)
    {
        use[l]=g;
        if (rec(l+1,kol)) return true;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b;
    cin>>n>>a>>b;
    vv.pb(a);
    vv.pb(a);
    vv.pb(a);
    vv.pb(a);
    vv.pb(b);
    vv.pb(b);
    if (rec(0,1)) cout<<1<<endl; else
    if (rec(0,2)) cout<<2<<endl; else
    if (rec(0,3)) cout<<3<<endl; else
    if (rec(0,4)) cout<<4<<endl; else
    if (rec(0,5)) cout<<5<<endl; else
    cout<<6<<endl;
}