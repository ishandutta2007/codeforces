#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 2e6 + 11;

int kol[27][27];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0; i<s.size()-1; i++)
    {
        kol[s[i]-'A'][s[i+1]-'A']++;
    }
    int l=0,r=0;
    for (int i=0; i<=26; i++)
    for (int j=0; j<=26; j++)
    if (kol[i][j]>kol[l][r]) {l=i; r=j;}
    cout<<char(l+'A')<<char(r+'A')<<endl;
}