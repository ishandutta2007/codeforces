#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const int N = 1000 + 11;
int main()
{
    int n;
    cin>>n;
    int k=0;
    for (int i=2; i<=10; i++)
        if (i+10==n) k+=4;
    if (n==20) k+=11;
    if (n==21||n==11) k+=4;
    cout<<k<<endl;
}