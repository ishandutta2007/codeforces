#include <iostream>
#include <fstream>
using namespace std;
int Q; int c, m, x;
int main()
{
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>c>>m>>x;
        cout<<min((c+m+x)/3, min(c, m))<<endl;
    }
}