#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back

const int N = 1e5 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    char ch='a';
    for (int i=0; i<s.size(); i++)
        if (s[i]>ch) ch=s[i];
    for (int i=0; i<s.size(); i++)
        if (ch==s[i]) cout<<ch;
}