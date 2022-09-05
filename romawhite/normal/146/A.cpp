#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define PB push_back

using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    int l=0,r=0;
    FOR(i,0,n)
    {
     int k=int(s[i])-48;
     if (k!=4 && k!=7) {cout<<"NO";return 0;}
     if (i<n/2) l+=k; else r+=k;
    }
    if (l==r) cout<<"YES";else cout<<"NO";

    return 0;
}