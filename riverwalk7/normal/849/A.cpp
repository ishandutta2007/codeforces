#include <iostream>
#include <fstream>
using namespace std;
int a[110];
int main()
{
    int N; cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    if(N%2==0||a[0]%2==0||a[N-1]%2==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
}