#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1e6 + 11;

map<string,bool> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        string t="";
        for (int j=0; j<s.size(); j++)
        {
            int pp=0;
            for (int p=0; p<t.size(); p++)
                if (t[p]==s[j]) pp=1;
            if (pp==0) t+=s[j];
        }
        sort(t.begin(),t.end());
        if (mt[t]==0) {ans++; mt[t]=1;}
    }
    cout<<ans<<endl;
}