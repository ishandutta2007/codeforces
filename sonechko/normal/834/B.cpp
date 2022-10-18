#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 11;
#define pb push_back

int k[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        k[s[i]-'A']=i+1;
    }
    int kol=0;
    for (int i=0; i<s.size(); i++)
    {
        if (b[s[i]-'A']==0) {b[s[i]-'A']=1; kol++;}
        if (kol>m) {cout<<"YES"<<endl; return 0;}
        if (k[s[i]-'A']==i+1) kol--;
    }
    cout<<"NO"<<endl;
}