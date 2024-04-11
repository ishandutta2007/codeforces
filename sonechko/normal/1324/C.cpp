#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;




void up()
{
    string s;
    cin>>s;
    int k=-1;
    int pos=-1;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='R')
    {
        k=max(k,j-pos);
        pos=j;
    }
    k=max(k,(int)s.size()-pos);
    cout<<k<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}