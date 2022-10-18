#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>m>>n;
    int p=1;
    if (m>n) p=2;
    while (n>0||m>0)
    {
        if (n>m) {cout<<"G";n--;}else
        if (m>n) {cout<<"B";m--;}else
        if (n==m&&p==2) {cout<<"G";n--;} else {cout<<"B"; m--;}
    }
    cout<<endl;
}