#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1073741825;
#define mod %MOD


const int N = 300 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int sum=0;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        sum+=l;
        m-=min(sum,8);
        sum-=min(sum,8);
        if (m<=0) {cout<<i<<endl; return 0;}
    }
    cout<<-1<<endl;
}