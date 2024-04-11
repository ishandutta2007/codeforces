#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N, n, x, d, h, best, best2;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>n>>x;
        best = 0;
        best2 = 0;
        for(int i=0; i<n; i++)
        {
            cin>>d>>h;
            best = max(best, d-h);
            best2 = max(best2, d);
        }
        if(best2 < x && best == 0)
        {
            cout<<-1<<endl;
            continue;
        }
        else if(best2 >= x)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<max(1, (x-best2-1)/best+2)<<endl;
        }
    }
}