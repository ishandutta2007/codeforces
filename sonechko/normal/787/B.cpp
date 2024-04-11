#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
int a[N],b[N];
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int k=0;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        k++;
        int p=0;
        for (int j=1; j<=l; j++)
        {
            int o;
            cin>>o;
            if (o<0) {a[-o]=k;if (b[-o]==k) {p=1;} }
            if (o>0) {b[o]=k; if (a[o]==k) {p=1;} }

        }
        if (p==0) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl;
}