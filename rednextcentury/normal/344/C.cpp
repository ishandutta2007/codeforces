#include <bits/stdc++.h>
using namespace std;
long long solve(long long a,long long b)
{
    if (a==0)return 0;
    if (b==0)return 0;
    if (a<b)swap(a,b);
    return a/b+solve(a%b,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;
}