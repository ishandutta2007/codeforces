#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const int N = 10000000 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    string ps="";
    for (int k=1; k<=(int)t.size()-(int)s.size(); k++)
        ps+="0";
    string p="";
    for (int k=1; k<=(int)s.size()-(int)t.size(); k++)
        p+="0";
    s=ps+s;
    t=p+t;
    if (s<t) cout<<"<"; else
    if (s==t) cout<<"="; else cout<<">";
}