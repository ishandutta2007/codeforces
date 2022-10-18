#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define all(a) a.begin(),a.end()
#define endl '\n'

using namespace std;

const int N=3e5+1;
const int inf=1e9+3;
const ll linf=1e18+3;
const int md=1e9+7;

int x1,y1,x2,y2,x,y,x3,y3,ans;

int kol(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
int _x[2],_y[2];
main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x1>>y1>>x2>>y2;
    ans=inf;
    x=x2+1;
    y=y2+1;
    x3=x2+1;
    y3=y2-1;
    ans=min(ans,kol(x1,y1,x,y)+kol(x3,y3,x1,y1)+6);
    ans=min(ans,kol(x1,y1,x3,y3)+kol(x,y,x1,y1)+6);

    x=x2-1;
    y=y2+1;
    x3=x2-1;
    y3=y2-1;
    ans=min(ans,kol(x1,y1,x,y)+kol(x3,y3,x1,y1)+6);
    ans=min(ans,kol(x1,y1,x3,y3)+kol(x,y,x1,y1)+6);

    x=x2+1;
    y=y2+1;
    x3=x2-1;
    y3=y2+1;
    ans=min(ans,kol(x1,y1,x,y)+kol(x3,y3,x1,y1)+6);
    ans=min(ans,kol(x1,y1,x3,y3)+kol(x,y,x1,y1)+6);

    x=x2+1;
    y=y2-1;
    x3=x2-1;
    y3=y2-1;
    ans=min(ans,kol(x1,y1,x,y)+kol(x3,y3,x1,y1)+6);
    ans=min(ans,kol(x1,y1,x3,y3)+kol(x,y,x1,y1)+6);
    cout<<ans;
}