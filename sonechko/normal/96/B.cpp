#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e6 + 11;
string ans;
void rec(int l, int sz, string s, string t, int ks)
{
    if (l==sz+1) {if (s<=t&&ans==""&&ks==0) ans=t; return;}
    if (ans!="") return;
    string d=t;
    string d1=d+"4";
    rec(l+1,sz,s,t+"4",ks+1);
    d1=d+"7";
    rec(l+1,sz,s,t+"7",ks-1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    if (s.size()%2!=0)
    {
        int k=s.size()+1;
        for (int i=1; i<=k/2; i++)
            cout<<"4";
        for (int i=1; i<=k/2; i++)
            cout<<"7";
        return 0;
    }
    int k=s.size();
    rec(1,k,s,"",0);
    if (ans!="") {cout<<ans<<endl; return 0;}
    k+=2;
    for (int i=1; i<=k/2; i++)
        cout<<"4";
    for (int i=1; i<=k/2; i++)
        cout<<"7";
}