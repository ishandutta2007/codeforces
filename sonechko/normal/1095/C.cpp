#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 500 + 11;
const int MOD = 1e9 + 7;

int kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0; i<=30; i++)
        if (n&(1<<i)) {kol[i]++; k--;}
    if (k<0) {cout<<"NO"<<endl; return 0;}
    for (int i=30; i>=1; i--)
    {
        int p=min(kol[i],k);
        k-=p;
        kol[i]-=p;
        kol[i-1]+=p*2;
    }
    if (k>0) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int i=0; i<=30; i++)
    for (int t=1; t<=kol[i]; t++)
    cout<<(1<<i)<<" ";

}
/**

**/