#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 3e5 + 11;

int a[N],b[N];


bool paralel(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if (x2-x1==x3-x4&&y2-y1==y3-y4) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
    }
    if (n%2==1) return cout<<"NO", 0;
    a[n+1]=a[1];
    b[n+1]=b[1];
    a[n+2]=a[2];
    b[n+2]=b[2];
    for (int i=1; i<=n/2; i++)
        if (paralel(a[i],b[i],a[i+1],b[i+1],
                    a[i+n/2],b[i+n/2],a[i+n/2+1],b[i+n/2+1])==0)
            return cout<<"NO", 0;
    cout<<"YES";
}