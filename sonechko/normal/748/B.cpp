#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back
int d[100];
int main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    vector<char> v1,v2;
    for (int i=0; i<s.size(); i++)
        if (s[i]!=t[i])
    {
        int p1=s[i]-'a'+1;
        int p2=t[i]-'a'+1;
        if (p1>p2) swap(p1,p2);
        if (d[p1]!=0&&d[p1]!=p2) {cout<<-1<<endl; return 0;}
        if (d[p2]!=0&&d[p2]!=p1) {cout<<-1<<endl; return 0;}
        if (d[p1]==0)
        {v1.pb(s[i]);
        v2.pb(t[i]);}
        d[p1]=p2;
        d[p2]=p1;
    } else
    {
        int p1=s[i]-'a'+1;
        if (d[p1]!=0&&d[p1]!=p1) {cout<<-1<<endl; return 0;}
        d[p1]=p1;
    }
    cout<<v1.size()<<"\n";
    for (int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" "<<v2[i]<<"\n";
}