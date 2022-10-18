#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 11;
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
int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    int ans1=k/(m*2);
    if (k%(m*2)!=0) ans1++;
    int ans2=(k-((m*2)*(ans1-1)))/2;
    if (k%2==1) ans2++;
    cout<<ans1<<" "<<ans2<<" ";
    if (k%2==0) cout<<"R"; else cout<<"L";
}