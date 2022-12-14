#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    char mn = 'z';
    for (auto x:s)
    {
        if (x>mn)cout<<"Ann"<<endl;
        else cout<<"Mike"<<endl;
        mn=min(mn,x);
    }
}