#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    set<int> s1,s2;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='8')s1.insert(i);
        else s2.insert(i);
    }

    int cur=0;
    while(n>11)
    {
        n--;
        if (cur%2==0)
        {
            if (s2.size()>0)s2.erase(s2.begin());
            else s1.erase(--s1.end());
        } else
        {
            if (s1.size()>0)s1.erase(s1.begin());
            else s2.erase(--s2.end());
        }
        cur=1-cur;
    }
    if (s1.size()==11 || (s1.size()>0 && *s1.begin()<*s2.begin()))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}