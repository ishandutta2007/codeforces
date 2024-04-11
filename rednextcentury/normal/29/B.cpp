# include <iostream>
# include <iomanip>
# include <stdio.h>
# include <algorithm>
#define EPS 1e-9
using namespace std;
int tim[2];
bool is[1000000];
int main()
{
    long double l,d,v;
    cin>>l>>d>>v;
    cin>>tim[0]>>tim[1];
    int now=0;
    int t=0;
    int cur=0;
    while(t<=10000)
    {
        if (cur==tim[now])
            cur=0,now=1-now;
        is[t]=now;
        t++,cur++;
    }
    long double ret=d/v;
    if (is[(int)(ret+EPS)])
    {

        ret=(int)(ret+EPS);
    cur=(ret+EPS);
    while(is[cur])
        cur++;
    ret=cur;
    }
    ret+=(l-d)/v;
    cout<<setprecision(10)<<ret<<endl;

}