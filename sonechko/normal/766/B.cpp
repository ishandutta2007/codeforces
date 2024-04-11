
#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define y1 khdifkne
#define ll long long
#define ld long double
int a[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=3; i<=n; i++)
    if (a[i-1]+a[i-2]>a[i]) {cout<<"YES"<<endl; return 0;}
    cout<<"NO"<<endl;
}