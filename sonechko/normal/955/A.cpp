#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
const int N = 5e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h,m,now,minuss,pluss,coll;
    cin>>h>>m>>now>>minuss>>coll>>pluss;
    int d=h*60+m;
    cout.precision(10);
    cout<<fixed;
    if (d>=1200)
    {
        ld res=((now+pluss-1)/pluss)*(ld)coll*0.8;
        cout<<res<<endl;
    } else
    {
        ld res1=((pluss+now-1)/pluss)*(ld)coll;
        ld res2=((pluss+(1200-d)*minuss+now-1)/pluss)*(ld)coll*0.8;
        if (res2<res1) res1=res2;
        cout<<res1<<endl;
    }
}