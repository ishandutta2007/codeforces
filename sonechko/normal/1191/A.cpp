#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 11;



int main()
{
    int x;
    cin>>x;
    if (x%4==1) cout<<"0 A"; else
    if (x%4==3) cout<<"2 A"; else
    if (x%4==2) cout<<"1 B"; else cout<<"1 A";
}