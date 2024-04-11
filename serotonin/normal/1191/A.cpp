#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    int n;
    cin >> n;
    if(n%4==1) puts("0 A");
    else if(n%4==3) puts("2 A");
    else if(n%4==0) puts("1 A");
    else puts("1 B");
}