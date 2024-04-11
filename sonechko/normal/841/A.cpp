#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 3e5 + 11;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        kol[s[i]-'a']++;
    }
    for (int i=0; i<=100; i++)
    if (kol[i]>m) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
}