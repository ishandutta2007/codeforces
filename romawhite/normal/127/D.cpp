#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;


int main(){
    string s;
    int b,i,j,k,l,m;
    cin>>s;
    int n = (int) s.length();
    int *a=new int[1000100];
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    //memset(a,0,sizeof(a));
    FOR(i,0,1000099)
        a[i]=0;
    FOR(i,0,n)
        a[z[i]]++;
    k=0;
    for(i=n;i>0;i--)
    {
        k+=a[i];
        if (k>=2 && z[n-i]==i)
        {
            FOR(j,0,i)
                cout<<s[j];
            //system("pause");
            return 0;
        }
    }
    cout<<"Just a legend";
    //system("pause");
    return 0;
}