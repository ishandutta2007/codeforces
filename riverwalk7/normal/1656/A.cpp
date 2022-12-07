#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
const int INF = 1e9+7;
int a[MAXN];
int l, h, lx, hx;
int T, N;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        l = INF;
        h = -1;
        for(int j=0; j<N; j++)
        {
            cin>>a[j];
            if(h < a[j])
            {
                h = a[j]; hx = j+1;
            }
            if(l > a[j])
            {
                l = a[j]; lx = j+1;
            }
        }
        cout<<lx<<" "<<hx<<endl;
    }
}