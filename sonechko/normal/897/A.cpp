#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ll long long
#define ss second
const ll N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        char ch1,ch2;
        cin>>l>>r>>ch1>>ch2;
        for (int j=l-1; j<r; j++)
            if (s[j]==ch1) s[j]=ch2;
    }
    cout<<s<<endl;
}