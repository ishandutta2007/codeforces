#include <bits/stdc++.h>
using namespace std;
bool Subseq(string s,string t)
{
    int j=0;
    for (int i=0;i<s.size();i++)
    {
        while(j<t.size() && t[j]!=s[i])j++;
        if (j==t.size())return 0;
        j++;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s,t,p;
        cin>>s>>t>>p;
        if (!Subseq(s,t))
            cout<<"NO"<<endl;
        else
        {
            int num[30]={0};
            for(auto x:p)num[x-'a']++;
            for(auto x:s)num[x-'a']++;
            for(auto x:t)num[x-'a']--;
            bool ok=1;
            for (int i=0;i<26;i++)
                if (num[i]<0)ok=0;
            if (ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }


}