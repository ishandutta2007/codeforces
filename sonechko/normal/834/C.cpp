#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll l,r;
        cin>>l>>r;
        ld p=pow(l*r,1.0/3.0);
        ll c=(ll)p-1;
        if (c!=0&&c!=-1&&c*c*c==l*r&&l%c==0&&r%c==0) cout<<"Yes"<<"\n"; else
        if (c!=-1&&(c+1)*(c+1)*(c+1)==l*r&&l%(c+1)==0&&r%(c+1)==0) cout<<"Yes\n"; else
        if ((c+2)*(c+2)*(c+2)==l*r&&l%(c+2)==0&&r%(c+2)==0) cout<<"Yes\n"; else
        cout<<"No\n";
    }
}