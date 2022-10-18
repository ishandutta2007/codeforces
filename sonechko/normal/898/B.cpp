#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n,a,b;
    cin>>n>>a>>b;
    for (long long i=0; i<=10000000; i++)
        if (n-a*i>=0&&(n-a*i)%b==0)
    {
        cout<<"YES"<<endl;
        cout<<i<<" "<<(n-a*i)/b<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}