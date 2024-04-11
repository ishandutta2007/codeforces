#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    while (1==1)
    {
        int ch=0;
        for (int j=1; j<s.size(); j++)
        if (s[j]=='U'&&s[j-1]=='R') {ch=j; break;} else
        if (s[j]=='R'&&s[j-1]=='U') {ch=j; break;}
        if (ch==0) break;
        string t="";
        for (int j=0; j<ch-1; j++)
            t+=s[j];
        t+="G";
        for (int j=ch+1; j<s.size(); j++)
        t+=s[j];
        s=t;
    }
    cout<<s.size()-1<<endl;
}