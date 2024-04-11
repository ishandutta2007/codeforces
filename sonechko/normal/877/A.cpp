#include<bits/stdc++.h>
using namespace std;


#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
#define ld long double

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s+="___________";
    int ans=0;
    for (int i=0; i<s.size()-7; i++)
    {
        if (s[i]=='D'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]=='i'&&s[i+4]=='l') ans++;
        if (s[i]=='O'&&s[i+1]=='l'&&s[i+2]=='y'&&s[i+3]=='a') ans++;
        if (s[i]=='S'&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='a') ans++;
        if (s[i]=='A'&&s[i+1]=='n'&&s[i+2]=='n') ans++;
        if (s[i]=='N'&&s[i+1]=='i'&&s[i+2]=='k'&&s[i+3]=='i'&&s[i+4]=='t'&&s[i+5]=='a') ans++;
    }
    if (ans==1)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}