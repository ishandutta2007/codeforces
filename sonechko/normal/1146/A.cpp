#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='a') k++;
    cout<<min((int)s.size(),k*2-1);
}
/**
8
1 1 1 1 210 140 84 60
**/