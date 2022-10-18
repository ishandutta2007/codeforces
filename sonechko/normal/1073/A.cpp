#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 1e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0; i<n-1; i++)
    if (s[i]!=s[i+1]) {cout<<"YES"<<endl; cout<<s[i]<<s[i+1]; return 0;}
    cout<<"NO"<<endl;
}