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
    int n,k;
    cin>>n>>k;
    bool q1=1,q2=1,q3=1,q4=1;
    string s[4];
    FOR(i,0,n)
    {
              cin>>s[0]>>s[1]>>s[2]>>s[3];
              int d=0;
              int l[4];
              FOR(j,0,4)
                        l[j]=s[j].length();
              string s1[4];
              FOR(j,0,4)
                        s1[j]="";
              FOR(j,0,4){
                         d=0;
                        for(int t=l[j]-1;t>=0;t--)
                        {
                                if(d==k) break;
                                if (s[j][t]=='a' || s[j][t]=='e' || s[j][t]=='i' || s[j][t]=='o' || s[j][t]=='u')
                                d++;
                                s1[j]+=s[j][t];
                        }
                        if (d!=k) {cout<<"NO";return 0;}
              }
              if (s1[0]!=s1[1] || s1[2]!=s1[3]) q1=0;
              if (s1[0]!=s1[2] || s1[1]!=s1[3]) q2=0;
              if (s1[0]!=s1[3] || s1[2]!=s1[1]) q3=0;
              if (s1[0]!=s1[1] || s1[2]!=s1[3] || s1[1]!=s1[2]) q4=0;
    }
    if (q4) {cout<<"aaaa";return 0;}
    if (q3) {cout<<"abba";return 0;}
    if (q2) {cout<<"abab";return 0;}
    if (q1) {cout<<"aabb";return 0;}
    cout<<"NO";
    return 0;
}