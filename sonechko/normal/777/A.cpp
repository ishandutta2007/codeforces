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
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    if (m==0&&(n%6==0||n%6>4)) cout<<0<<endl; else
    if (m==1&&(n%6==1||n%6==4)) cout<<0<<endl; else
    if (m==2&&(n%6==2||n%6==3)) cout<<0<<endl; else
    if (m==0&&(n%6==1||n%6==2)) cout<<1<<endl; else
    if (m==1&&(n%6==0||n%6==3)) cout<<1<<endl; else
    if (m==2&&n%6>3) cout<<1<<endl; else cout<<2<<endl;
}