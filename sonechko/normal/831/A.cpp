#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 11;
#define pb push_back

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int l=1;
    cin>>a[1];
    for (int i=2; i<=n; i++)
    {
            cin>>a[i];
        if (a[i]==a[i-1])
        {
            if (l==3) {cout<<"NO"<<endl; return 0;}
            l=2;
        }
        if (a[i]>a[i-1])
        {
            if (l!=1) {cout<<"NO"<<endl; return 0;}
        }
        if (a[i]<a[i-1]) l=3;
    }
    cout<<"YES"<<endl;
}