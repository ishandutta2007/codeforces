# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<cmath>
# include <vector>
# include <iomanip>
#define EPS 1e-9
using namespace std;
int p[100];
int main()
{
    int h,w;
    cin>>h>>w;
    bool is=0;
    if (h<w)
        swap(h,w),is=1;
    p[0]=1;
    for (int i=1;i<=29;i++)
    {
        p[i]=p[i-1]*2;
    }
    for (int i=29;i>=0;i--)
    {
        long double x=p[i];
        if (x>w)
            continue;
        long double g=h/x;
        if (g>1.25)
            g=1.25;
        if (g<0.8)
            continue;
        if (!is || (is && (int)(x*g+EPS) <w))
        cout<<(int)(x*g+EPS)<<" "<<(int)(x+EPS)<<endl;
        else
            cout<<(int)(x+EPS)<<" "<<(int)(x*g+EPS)<<endl;
        return 0;
    }
}