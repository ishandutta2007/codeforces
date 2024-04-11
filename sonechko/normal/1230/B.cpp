#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if ((int)s.size()==1&&k>0) return cout<<"0", 0;
    for (int i=0; i<s.size(); i++)
        if (i==0&&s[i]>'1'&&k>0) {k--; s[i]='1';} else
        if (i>0&&s[i]>'0'&&k>0) {k--; s[i]='0';}
    cout<<s;
}