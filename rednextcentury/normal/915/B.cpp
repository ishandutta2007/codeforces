#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,p,l,r;
    cin>>n>>p>>l>>r;
    if (l==1 && r==n){
        cout<<0<<endl;
    } else if (l==1) {
        cout<<abs(r-p)+1<<endl;
    } else if (r==n) {
        cout<<abs(p-l)+1<<endl;
    } else {
        cout<<min(abs(p-l)+r-l+2,abs(p-r)+r-l+2)<<endl;
    }
}