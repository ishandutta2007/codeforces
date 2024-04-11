#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;



void up()
{
    int n;
    cin>>n;
    if (n%2==1) {cout<<0; return;}
    cout<<(1<<(n/2));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    up();
}
/**
1 2 3 4 5 6 7 8 9 10
X
2 3 4 5 6 7 8 9 10
  X
2 4 5 6 7 8 9 10
    X
2 4 6 7 8 9 10
      X
**/