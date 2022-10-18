#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

map<int,bool> mt;
ll x[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x[i];
        mt[x[i]]=1;
    }
    for (int i=1; i<=n; i++)
    {
        ll k=1;
        for (int j=0; j<=35; j++)
        {
            if (x[i]+k+k<=1000000000&&mt.find(x[i]+k)!=mt.end()&&mt.find(x[i]+k+k)!=mt.end())
            {
                cout<<"3"<<endl;
                cout<<x[i]<<" "<<x[i]+k<<" "<<x[i]+k+k<<endl;
                return 0;
            }
            k*=2ll;
        }
    }
    for (int i=1; i<=n; i++)
    {
        ll k=1;
        for (int j=0; j<=35; j++)
        {
            if (x[i]+k<=1000000000&&mt.find(x[i]+k)!=mt.end())
            {
                cout<<"2"<<endl;
                cout<<x[i]<<" "<<x[i]+k<<endl;
                return 0;
            }
            k*=2ll;
        }
    }
    cout<<1<<endl;
    cout<<x[1]<<endl;
}