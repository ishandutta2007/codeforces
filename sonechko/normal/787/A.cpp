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
map<int,bool> use;
int main()
{
    sync;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> v1,v2;
    for (int i=0; i<=10000; i++)
    use[b+i*a]=1;
    for (int i=0; i<=10000; i++)
    if (use[d+i*c]==1) {cout<<d+i*c<<endl; return 0;}
    cout<<-1<<endl;
}