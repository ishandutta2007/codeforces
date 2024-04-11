#include<bits/stdc++.h>
using namespace std;

#define ff first
#define pb push_back
#define ss second
#define mp make_pair
#define ll long long
#define mod %MOD

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    int ans1=abs(x-y)*t1;
    int ans2=abs(x-y)*t2+abs(x-z)*t2+t3*3;
    if (ans2<=ans1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}