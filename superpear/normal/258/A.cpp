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
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

string s;
int e;
int main()
{
    cin>>s;
    e=0;
    for (int i=0;i<s.size();i++)
        if (s[i]=='0')
        {
            e=i;
            break;
        }
    for (int i=0;i<e;i++) cout<<s[i];
    for (int i=e+1;i<s.size();i++) cout<<s[i];
    cout<<endl;
    return 0;
}