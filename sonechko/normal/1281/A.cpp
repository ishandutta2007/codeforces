#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;

void up()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    if (s[0]=='o') cout<<"FILIPINO\n"; else
    if (s[0]=='u') cout<<"JAPANESE\n"; else
    cout<<"KOREAN\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}
/**
8
1 1 1 1 210 140 84 60
**/