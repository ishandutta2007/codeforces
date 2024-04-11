#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        int r=0;
        for (int j=0; j<=100; j++)
            if (l-j*3>=0&&(l-j*3)%7==0) r=1;
        if (r==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}