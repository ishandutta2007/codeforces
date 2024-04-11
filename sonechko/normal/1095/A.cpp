#include<bits/stdc++.h>
using namespace std;

const int N = 5000 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    int p=1,d=0;
    while (p<s.size())
    {
        cout<<s[p];
        d++;
        p+=d;
    }
    cout<<endl;
}