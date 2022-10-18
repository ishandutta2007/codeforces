#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k=0;
    for (int i=1; i<=n; i++)
    {
        k+=i;
        if (k==n) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl; return 0;
}