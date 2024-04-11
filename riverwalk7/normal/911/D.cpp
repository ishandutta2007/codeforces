#include <iostream>
#include <fstream>
#define MAXN 1600
using namespace std;
int N, M;
int a[MAXN];
int l, r;
int v;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(a[i]>a[j])
            {
                ++v;
            }
        }
    }
    cin>>M;
    for(int i=0; i<M; i++)
    {
        cin>>l>>r;
        int k= r-l+1;
        if((k*(k-1))%4==2)
        {
            ++v;
        }
        if(v%2==0)
        {
            cout<<"even"<<endl;
        }
        else
        {
            cout<<"odd"<<endl;
        }
    }
}