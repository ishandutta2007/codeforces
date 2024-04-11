#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    for(int i = 2; i <= a; i++){
        while(a % i == 0) cout<<i,a/=i;
    }
}