#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v1,v2,v3,vm;
    cin>>v1>>v2>>v3>>vm;
    for (int p=1; p<=300; p++)
    for (int d=1; d<p; d++)
    for (int x=1; x<d; x++)
    if (v1*2>=p&&v1<=p&&v2*2>=d&&v2<=d&&v3*2>=x&&v3<=x&&
        vm<=p&&vm<=d&&vm<=x&&vm*2>=x&&vm*2<d&&vm*2<p)
    {
        cout<<p<<endl;
        cout<<d<<endl;
        cout<<x<<endl;
        return 0;
    }
    cout<<-1<<endl;
}