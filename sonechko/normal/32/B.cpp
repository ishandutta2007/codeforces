#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    string t="";
    for (int i=0; i<s.size(); i++)
    if (s[i]=='.') {t+="0";} else
    if (s[i]=='-'&&s[i+1]=='.')
    {
        t+="1";
        i++;
    } else
    {
        t+="2";
        i++;
    }
    cout<<t<<endl;
}