#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
int main()
{
    long long n,m,x;
    cin>>n>>m>>x;
    cout<<(n+(n%x!=0)*x)/x*((m+(m%x!=0)*x)/x);
}