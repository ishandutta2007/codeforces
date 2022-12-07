#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int N, a, b, c;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a>>b>>c;
        cout<<min(max(0, (c-(b-a+c+2)/2+1)), c+1)<<endl; // x1 + x2 = c, 0 <= x1 <= c
    }
}