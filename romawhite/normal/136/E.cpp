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
    string s;
    cin>>s;
    int a[101000];
    int k0=0,k1=0,k2=0;
    bool q00=0,q01=0,q10=0,q11=0;
    int n=s.length();
    FOR(i,0,n)
    {
              if (s[i]=='0') {a[i]=0;k0++;}
              if (s[i]=='1') {a[i]=1;k1++;}
              if (s[i]=='?') {a[i]=2;k2++;}
    }
    if (k2+k1-k0>=2) q11=1;
    if (k0+k2-k1>=1) q00=1;
    int l1,l0;
    l1=(k0+k2-k1+n%2)/2;
    l0=k2-l1;
    if (l1>=0 && l1<=k2){
    if (a[n-1]==0 || (a[n-1]==2 && l0)) q10=1;
    if (a[n-1]==1 || (a[n-1]==2 && l1)) q01=1;}
    if (q00) cout<<"00"<<endl;
    if (q01) cout<<"01"<<endl;
    if (q10) cout<<"10"<<endl;
    if (q11) cout<<"11"<<endl;
    //system("pause");
    return 0;
}