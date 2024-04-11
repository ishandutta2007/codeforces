#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a;
    cin>>a;
    for (int n=a; n<=20000; n++)
    {
        int k=0,nn=n;
        while (nn>0)
        {
            k+=nn%10;
            nn/=10;
        }
        if (k%4==0) return cout<<n,0;
    }
}
/**
8
1 1 1 1 210 140 84 60
**/