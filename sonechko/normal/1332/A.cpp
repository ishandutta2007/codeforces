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
    int a,b,c,d;
    int x,y,x1,y1,x2,y2;
    cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
    if (x1==x&&x==x2&&(a+b)!=0)
    {
        cout<<"NO\n";
    } else
    if (y1==y&&y==y2&&(c+d)!=0)
    {
        cout<<"NO\n";
    } else
    {
        x=x+b-a;
        y=y+d-c;
        if (x>=x1&&x<=x2&&y>=y1&&y<=y2)
            cout<<"YES\n"; else cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--) up();
}