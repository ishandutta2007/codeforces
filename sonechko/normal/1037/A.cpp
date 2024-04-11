#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int k=0;
    int t=1;
    while (n>0)
    {
        k++;
        n-=t;
        t*=2;
    }
    cout<<k<<"\n";
}
/**
1 - 1
2 - 1 1
3 - 1 2
4 - 1 2 1
5 - 1 2 2
6 - 1 2 3
7 - 1 2 4
**/