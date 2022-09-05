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
    string s1,s2;
    cin>>s1>>s2;
    int k4=0,k7=0;
    FOR(i,0,s1.length())
    if (s1[i]!=s2[i])
    if (s1[i]=='4') ++k4;else ++k7;
    cout<<max(k4,k7);
    //system("pause");
    return 0;
}