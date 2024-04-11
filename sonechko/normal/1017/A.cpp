#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int l,r,k,p;
    cin>>l>>r>>k>>p;
    int sum=l+r+k+p,pos=1;
    for (int i=2; i<=n; i++)
    {
        cin>>l>>r>>k>>p;
        int x=l+r+k+p;
        if (x>sum) pos++;
    }
    cout<<pos<<endl;
}