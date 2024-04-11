#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 3e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    int res=0;
    while (cin>>s)
    {
        int ans=0;
        for (int i=0; i<s.size(); i++)
            if (s[i]>='A'&&s[i]<='Z') ans++;
        res=max(res,ans);
    }
    cout<<res<<endl;
}