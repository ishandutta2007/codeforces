#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 11;
int main()
{
    int n;
    cin>>n;
    int p=0,k=0;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        if (t!=0) {p=i;}
        k+=t;
    }
    if (p==0&&k==0) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    if (k!=0) cout<<1<<endl<<1<<" "<<n<<endl; else
    cout<<2<<endl<<1<<" "<<p-1<<endl<<p<<" "<<n<<endl;
}