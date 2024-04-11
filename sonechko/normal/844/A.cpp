#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e6 + 11;
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k;
    cin>>k;
    if (k>s.size()) {cout<<"impossible"<<endl; return 0;}
    for (int i=0; i<s.size(); i++)
    if (use[s[i]-'a']==0) {k=max(k-1,0); use[s[i]-'a']=1;}
    cout<<k<<endl;
}