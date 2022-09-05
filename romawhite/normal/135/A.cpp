#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n;
    cin>>n;
    int a[100100];
    bool q=1;
    FOR(i,0,n)
    {
              cin>>a[i];
              if (a[i]!=1) q=0;
    }
    sort(a,a+n);
    if (q)
    {
          FOR(i,0,n-1)
                      cout<<"1 ";
          cout<<'2';
          //system("pause");
          return 0;
    }
    cout<<"1 ";
    FOR(i,0,n-1)
                cout<<a[i]<<' ';
    //system("PAUSE");
    return 0;
}