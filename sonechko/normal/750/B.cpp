#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
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
#define tab difjke
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int k=0;
    for (int i=1; i<=n; i++)
    {
        int m;
        cin>>m;
        string s;
        cin>>s;
        if (k==0&&s!="South") {cout<<"NO"<<endl; return 0;}
        if (k==20000&&s!="North") {cout<<"NO"<<endl; return 0;}
        if (s=="South") k+=m; else
        if (s=="North") k-=m;
        if (k<0||k>20000) {cout<<"NO"<<endl; return 0;}
    }
    if (k!=0) cout<<"NO"<<endl; else cout<<"YES"<<endl;
}