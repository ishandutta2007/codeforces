#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            if ((i+j)%2==0) cout<<'B'; else cout<<'W';
        cout<<endl;
    }
}
/**
B.B.B.......
..WBW.......
BW.WB.......
.B.B........
B.B.........
............
............
............
............
............
............
............



**/