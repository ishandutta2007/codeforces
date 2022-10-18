#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
int get(string s)
{
    int kol=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u') kol++;
    return kol;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t,d;
    getline(cin,s);
    getline(cin,t);
    getline(cin,d);
    if (get(s)==5&&get(t)==7&&get(d)==5) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}