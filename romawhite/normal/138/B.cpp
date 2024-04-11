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
    int a[10];
    cin>>s;
    memset(a,0,sizeof(a));
    FOR(i,0,s.length())
    a[int(s[i])-48]++;
    int k=0,l=0,m=0;
    FOR(i,1,5)
    k+=min(a[i],a[10-i]);
    k+=a[5];
    FOR(i,1,5)
    l+=min(a[i],a[9-i]);
    m=min(a[0],a[9]);
    if (k==0)
    {
             FOR(j,1,10)
                        FOR(t,0,a[j])
                        cout<<j;
             FOR(t,0,a[0])
             cout<<0;
             cout<<endl;
             FOR(j,1,10)
                        FOR(t,0,a[j])
                        cout<<j;
             FOR(t,0,a[0])
             cout<<0;
             cout<<endl;
             //system("pause");
             return 0;
    }
    int mm=-1;int d=0;
    FOR(j,1,6)
    {
              int a1[10],a2[10];
              FOR(i,0,10)
              {a1[i]=a[i];a2[i]=a[i];}
              if (a[j]==0 || a[10-j]==0) continue;
              a1[j]--;a2[10-j]--;
              int m=0;
              FOR(t,0,10)
              m+=min(a1[t],a2[9-t]);
              m+=max(a[0]-a[9],0);
              //if (j==5) cout<<m<<endl;
              /*FOR(t,0,5)
              m+=2*(min (a[t],a[9-t]);
              if (a[9-j]>a[j]) m++;
              if (a[j-1]>a[10-j]) m++;
              m+=max(a[0]-a[9],0);*/
              if (m>mm) {mm=m;d=j;}
    }
    //cout<<d<<endl;
    int a1[10],a2[10];
    FOR(i,0,10)
    {a1[i]=a[i];a2[i]=a[i];}
    a1[d]--;a2[10-d]--;
    vector<int>r1,r2;
    FOR(i,0,max(a[0]-a[9],0))
    {r1.PB(0);r2.PB(0);}
    a1[0]-=max(a[0]-a[9],0);a2[0]-=max(a[0]-a[9],0);
    r1.PB(d);r2.PB(10-d);
    FOR(i,0,10)
    {
     FOR(j,0,min(a1[i],a2[9-i]))
       {r1.PB(i);r2.PB(9-i);}
       int r=min(a1[i],a2[9-i]);
     a1[i]-=r;
     a2[9-i]-=r;
    }
    /*FOR(i,0,10)
    cout<<a1[i]<<' '<<a2[i]<<endl;*/
    FOR(i,0,10)
    FOR(j,0,a1[i])
    r1.PB(i);
    FOR(i,0,10)
    FOR(j,0,a2[i])
    r2.PB(i);
    for(int i=r1.size()-1;i>=0;i--)
    cout<<r1[i];
    cout<<endl;
    for(int i=r2.size()-1;i>=0;i--)
    cout<<r2[i];
    //system("pause");
    return 0;
}