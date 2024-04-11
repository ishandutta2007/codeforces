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
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    int sum=x1+x2+x3+x4;
    if (sum%2==1) return cout<<"NO", 0;
    sum/=2;
    if (x1==sum||x2==sum||x3==sum||x4==sum||x1+x2==sum||x1+x3==sum||
        x1+x4==sum||x2+x3==sum||x2+x4==sum||x3+x4==sum) return cout<<"YES", 0;
    cout<<"NO";
}
/**
8
1 1 1 1 210 140 84 60
**/