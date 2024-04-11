#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        long long l,r;
        cin>>l>>r;
        long long ret=0;
        if (l%2==0)
            ret+=l,l++;
        if (r%2)
            ret-=r,r--;
        cout<<ret+(r-l+1)/2<<endl;
    }
}