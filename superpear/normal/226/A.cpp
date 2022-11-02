#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

int n,m;

int getpow(int s)
{
    if (s==0) return 1;
    int d=getpow(s/2);
    d=(long long)d*d%m;
    if (s%2==1) d=(long long)d*3%m;
    return d;
}

int main()
{
    cin>>n>>m;
    cout<<(getpow(n)+m-1)%m<<endl;
    return 0;
}