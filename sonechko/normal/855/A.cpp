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
string a[101];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        int k=0;
        for (int j=0; j<i; j++)
            if (a[j]==a[i]) k=1;
        if (k==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
}