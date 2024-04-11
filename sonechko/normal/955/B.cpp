#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
const int N = 5e5 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    kol[s[i]-'a']++;
    int ks1=0,ks2=0;
    for (int i=0; i<26; i++)
        if (kol[i]>1) ks2++; else
        if (kol[i]==1) ks1++;
    if (ks1+ks2>4) cout<<"No"<<endl; else
    if (ks1+ks2==4) cout<<"Yes"<<endl; else
    if (ks1+ks2==3&&ks2>0) cout<<"Yes"<<endl; else
    if (ks2==2) cout<<"Yes"<<endl; else cout<<"No"<<endl;
}