#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int w,h;
    cin>>w>>h;
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    for (int i=h; i>=1; i--)
    {
        w+=i;
        if (i==r1) w-=l1;
        if (i==r2) w-=l2;
        if (w<0) w=0;
    }
    cout<<w<<endl;
}