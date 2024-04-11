#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 100 + 11;
const int MOD = 998244353;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int kol=(n+2)/2;
    cout<<kol<<endl;
    for (int i=1; i<=n; i++)
        if (i<=kol) cout<<1<<" "<<i<<"\n"; else
        cout<<(i-kol)+1<<" "<<kol<<"\n";
}
/**
1 - 1
2 - 2
3 - 2
4 - 3
5 - 3
6 - 4
7 - 4

**/