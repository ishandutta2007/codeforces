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

int main()
{
    int a,n,b;
    cin>>a>>b>>n;
    int flag=1;
    for (int i=0;i<=9;i++)
        if ((a*10+i)%b==0) {flag=0;a=a*10+i;break;}
    if (flag==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<a;
    for (int i=1;i<=n-1;i++) cout<<"0";
    cout<<endl;

    return 0;
}