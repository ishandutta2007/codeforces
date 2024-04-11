#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        if (abs(a-b)%5==0) {cout<<abs(a-b)/5<<"\n"; continue;}
        if (abs(a-b)%5==1||abs(a-b)%5==2) {cout<<abs(a-b)/5+1<<"\n"; continue;}
        cout<<abs(a-b)/5+2<<"\n";
    }
}