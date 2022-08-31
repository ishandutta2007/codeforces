#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int N;
    cin>>N;
    vector<double> T(N);
    vector<double> R(N);
    for(int i = 0; i < N; ++i)
    {
        cin>>T[i];
    }
    for(int i = 0; i < N; ++i)
    {
        cin>>R[i];
    }
    vector<double> P(N);
    cout.precision(10);
    double one=0;
    double two=0;
    for(int i = 0; i < N; ++ i)
    {
        double s = T[i]+R[i];
        double b = one-two-s;
        double c = -(R[i]-(1-one)*s);
        //cout<<T[i]<<' '<<R[i]<<' '<<b<<' '<<c<<endl;
        double d = b*b - 4*c;
        double dd = sqrt(max(d, (double)0));
        //cout<<dd<<endl;
        double x1 = (-b+dd)/2;
        double x2 = (-b-dd)/2;
        //cout<<"A"<<x1<<' '<<x2<<endl;
        one += max(x1, x2);
        P[i] = max(x1, x2);
        two += s-max(x1, x2);
        cout<<x1<<' ';
    }
    cout<<endl;
    for(int i = 0; i < N; ++i)
    {
        cout<<T[i]+R[i]-P[i]<<' ';
    }
}