#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e3 + 11;


int main()
{
    int n;
    cin>>n;
    int ks=100000,tt=0;
    for(int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (l!=r) {cout<<"rated"<<endl; return 0;}
        if (l>ks) tt=1;
        ks=l;
    }
    if (tt==1) cout<<"unrated"<<endl; else cout<<"maybe"<<endl;
}