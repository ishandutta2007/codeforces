#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;

ld x[N],y[N];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ld r;
    cin>>n>>r;
    cout.precision(10);
    cout<<fixed;
    cin>>x[1];
    y[1]=r;
    for (int i=2; i<=n; i++)
    {
        cin>>x[i];
        y[i]=r;
        for (int j=1; j<i; j++)
        {
            ld b=-2*y[j];
            ld c=y[j]*y[j]+(x[j]-x[i])*(x[j]-x[i])-4*r*r;
            ld D=b*b-4*c;
            if (D<0) continue;
            D=sqrt(D);
            ld rr=(D-b)/(ld)2;
            y[i]=max(y[i],rr);
        }
    }
    for (int i=1; i<=n; i++)
        cout<<y[i]<<" ";
    cout<<endl;
}