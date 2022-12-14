#include <bits/stdc++.h>
using namespace std;
int a[10000];
set<char> S;
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char mn='z';
    char mx='a';
    for (int i=0;i<s.size();i++)
        mn=min(mn,s[i]),mx=max(mx,s[i]),S.insert(s[i]);
    if (k>n)
    {
        cout<<s;
        while(k>n)
        {
            k--;
            cout<<mn;
        }
        cout<<endl;
    }
    else
    {
        string ret;
        for (int i=0;i<k;i++)
            ret+=s[i];
        for (int i=k-1;i>=0;i--)
        {
            if (s[i]!=mx)
            {
                ret[i]=*S.upper_bound(s[i]);
                for (int j=i+1;j<k;j++)
                    ret[j]=mn;
                cout<<ret<<endl;
                return 0;
            }
        }
    }
}