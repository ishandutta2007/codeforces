#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int p=3;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (x==p) {cout<<"NO"<<endl; return 0;}
        if (p!=1&&x!=1) p=1; else
        if (p!=2&&x!=2) p=2; else p=3;
    }
    cout<<"YES"<<endl;
}