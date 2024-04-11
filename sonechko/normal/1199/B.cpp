#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int N = 2e5 + 11;



void up()
{
    ld h,l;
    cin>>h>>l;
    cout.precision(10);
    cout<<fixed<<(l*l-h*h)/(2*h)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    while (t--)
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