#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s;
    int n;
    cin>>n;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='O'||s[i]=='o') s[i]='0'; else
        if (s[i]=='l'||s[i]=='L'||s[i]=='i'||s[i]=='I') s[i]='1'; else
        if (s[i]>='A'&&s[i]<='Z') s[i]=char((s[i]-'A')+'a');
    t=s;

    for (int j=1; j<=n; j++)
    {
        string s;
        cin>>s;
        for (int i=0; i<s.size(); i++)
        if (s[i]=='O'||s[i]=='o') s[i]='0'; else
        if (s[i]=='l'||s[i]=='L'||s[i]=='i'||s[i]=='I') s[i]='1'; else
        if (s[i]>='A'&&s[i]<='Z') s[i]=char((s[i]-'A')+'a');
        if (s==t) {cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
}