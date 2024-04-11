
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

bool g(char ch)
{
    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    string t="";
    for (int i=0; i<s.size(); i++)
    {
        if (t.size()>1&&g(t[t.size()-1])&&g(t[t.size()-2])&&g(s[i])&&(s[i]!=t[t.size()-1]||s[i]!=t[t.size()-2]||t[t.size()-1]!=t[t.size()-2]))
        {
            cout<<t<<" ";
            t="";
        }
        t+=s[i];
    }
    cout<<t<<endl;
}