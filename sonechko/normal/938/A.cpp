#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

bool g(char ch)
{
    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y')
        return true;
    return false;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    while (1==1)
    {
        string t="";
        t+=s[0];
        int cc=0;
        for (int p=1; p<s.size(); p++)
            if (g(s[p])&&g(s[p-1])&&cc==0) cc=1; else
                t+=s[p];
        if (cc==0) break;
        s=t;
    }
    cout<<s<<endl;
}