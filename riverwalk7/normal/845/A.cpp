#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
int a[210];
int main()
{
    cin>>N;
    for(int i=0; i<2*N; i++)
    {
        cin>>a[i];
    }
    sort(a, a+2*N);
    if(a[N-1]==a[N])
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}