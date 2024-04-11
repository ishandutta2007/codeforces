#include <iostream>
#define INF 1e9
using namespace std;
int N;
int c, d;
int minrating, maxrating;
int main()
{
    cin>>N;
    minrating=-INF;
    maxrating=INF;
    for(int i=0; i<N; i++)
    {
        cin>>c>>d;
        if(d==1)
        {
            minrating=max(minrating+c, 1900+c);
            maxrating+=c;
        }
        else
        {
            maxrating=min(maxrating+c, 1899+c);
            minrating+=c;
        }
    }
    if(minrating>maxrating)
    {
        cout<<"Impossible"<<endl;
    }
    else if(maxrating>(INF/2))
    {
        cout<<"Infinity"<<endl;
    }
    else
    {
        cout<<maxrating<<endl;
    }
}