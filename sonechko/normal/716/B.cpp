#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
int use[N];
int main()
{
    sync;
    string s;
    cin>>s;
    int ans=0;
    s='.'+s;
    for (int i=0; i<26; i++)
    {
        if (s[i]>='A'&&s[i]<='Z') {if (use[s[i]-'A']==0) ans++; use[s[i]-'A']++;} else {use[26]++; ans++;}
    }
    for (int i=26; i<s.size(); i++)
    {
        if (s[i-26]>='A'&&s[i-26]<='Z') {if (use[s[i-26]-'A']==1) ans--; use[s[i-26]-'A']--;} else {use[26]--; ans--;}
        if (s[i]>='A'&&s[i]<='Z') {if (use[s[i]-'A']==0) ans++; use[s[i]-'A']++;} else {use[26]++; ans++;}
        if (ans==26)
        {
            for (int j=i-25; j<=i; j++)
            if (s[j]=='?')
            {
                for (int k=0; k<=25; k++)
                if (use[k]==0) {use[k]=1; s[j]=(k+'A'); break;}
            }
            for (int j=1; j<s.size(); j++)
                if (s[j]=='?') cout<<"A"; else cout<<s[j];
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}