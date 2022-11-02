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
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int monthc[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

string s,st,ans;
vector<string> a;
int e,c;

bool check(string s)
{
    if ((s[2]=='-')&&(s[5]=='-'))
    {
        for (int i=0;i<s.size();i++)
            if ((i!=2)&&(i!=5))
                if ((s[i]<'0')||(s[i]>'9')) return false;
        int day,month,year;
        day=(s[0]-48)*10+(s[1]-48);
        month=(s[3]-48)*10+(s[4]-48);
        year=(s[6]-48)*1000+(s[7]-48)*100+(s[8]-48)*10+(s[9]-48);
        if ((year>=2013)&&(year<=2015))
        {
            if ((month>=1)&&(month<=12))
            {
                if ((day>0)&&(day<=monthc[month]))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>s;
    for (int i=0;i<=s.size()-10;i++)
    {
        st="";
        for (int j=i;j<=i+9;j++) st+=s[j];
        if (check(st)) a.p_b(st);
    }
    sort(a.begin(),a.end());
    e=0;ans="";c=1;
    for (int i=1;i<a.size();i++)
        if (a[i]==a[i-1]) ++c; else
        {
            if (c>e) e=c,ans=a[i-1];
            c=1;
        }
    if (c>e) ans=*(a.end()-1);
    cout<<ans<<endl;

    return 0;
}