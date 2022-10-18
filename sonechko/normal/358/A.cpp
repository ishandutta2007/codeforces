#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1e5 + 11;
int x[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>x[i];
    for (int i=1; i<n; i++)
    for (int j=1; j<n; j++)
    {
        int xx=min(x[i],x[i+1]);
        int xxx=max(x[i],x[i+1]);
        int yy=min(x[j],x[j+1]);
        int yyy=max(x[j],x[j+1]);
        if (xx<yy&&yy<xxx&&yyy>xxx) {cout<<"yes"<<endl; return 0;}
    }
    cout<<"no"<<endl;
}