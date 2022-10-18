#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int d1=(n/10)*10;
    int d2=(n/10+1)*10;
    if (abs(d1-n)<abs(d2-n)) cout<<d1<<endl;
    else cout<<d2<<endl;
}