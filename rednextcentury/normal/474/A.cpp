#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <queue>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define B 0
#define W 1
#define MOD 1000000007
using namespace std;
int main()
{
    string k="qwertyuiopasdfghjkl;zxcvbnm,./";
    int m=k.length();
    char x;
    cin>>x;
    string s;
    cin>>s;
    int n=s.length();
    for (int i=0;i<n;i++)
    {
        int idx;
        for (int po=0;po<m;po++)
        {
            if (k[po]==s[i])
                idx=po;
        }
        if (x=='R')
            cout<<k[idx-1];
        else
            cout<<k[idx+1];
    }
    cout<<endl;

}