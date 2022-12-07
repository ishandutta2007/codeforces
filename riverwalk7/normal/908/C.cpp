#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#define MAXN 1010
using namespace std;
double x[MAXN], y[MAXN];
int xx[MAXN];
int a, N, R;
int main()
{
    cin>>N>>R;
    double RR = R;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        xx[i] = x[i] = a;
        for(int j=0; j<i; j++)
        {
            if(abs(xx[i]-xx[j]) <= (2*R))
            {
                y[i] = max(y[i], y[j] + sqrt(4*RR*RR-(xx[i]-xx[j])*(xx[i]-xx[j])));
            }
        }
        if(y[i]==0)
        {
            x[i] = xx[i];
            y[i] = R;
        }
        cout<<fixed<<setprecision(7)<<y[i];
        if(i<(N-1))
            cout<<" ";
        else
            cout<<""<<endl;
    }
}