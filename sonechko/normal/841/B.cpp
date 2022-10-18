#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            if (a[i]%2==1) {cout<<"First"<<endl; return 0;}
        }
    cout<<"Second"<<endl;
}