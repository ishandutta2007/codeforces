#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

int use[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (use[l]==0) {use[l]=1; vv.pb(i);}
    }
    if (vv.size()<k) {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
    for (int j=0; j<k; j++)
        cout<<vv[j]<<" ";
}