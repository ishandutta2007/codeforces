#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 17;
int a[N];
char c[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    char ch='z';
    a[s.size()]=0;
    c[s.size()]=ch;
    for (int i=s.size()-1; i>=0; i--)
    {
        if (s[i]<=ch) {ch=s[i]; a[i]=i;} else a[i]=a[i+1];
        c[i]=ch;
    }
    vector<char> t;
    string u="";
    for (int i=0; i<=s.size(); i++)
        {
        while (t.size()>0&&t[t.size()-1]<=c[i])
        {
            u+=t[t.size()-1];
            t.pop_back();
        }
        if (s.size()!=i) t.pb(s[i]);
        while (t.size()>0&&t[t.size()-1]<=c[i])
        {
            u+=t[t.size()-1];
            t.pop_back();
        }
        }
    cout<<u<<endl;
}