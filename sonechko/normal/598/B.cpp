#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        k=k%(r-l+1);
        l--;
        r--;
        string e="";
        for (int j=k; j>=1; j--)
            e+=s[r-j+1];
        for (int j=1; j<=r-l+1-k; j++)
            e+=s[l+j-1];
        for (int j=0; j<e.size(); j++)
            s[l+j]=e[j];
    }
    cout<<s<<endl;
}