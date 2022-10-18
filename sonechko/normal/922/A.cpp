#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 2e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y;
    cin>>x>>y;
    swap(x,y);
    if (x==0) cout<<"No"<<endl; else
    if (x==1&&y==0) cout<<"Yes"<<endl; else
    if (x==1) cout<<"No"<<endl; else
    {
        y-=x-1;
        if (y<0) cout<<"No"<<endl; else
        if (y%2==0) cout<<"Yes"<<endl; else
        cout<<"No"<<endl;
    }
}