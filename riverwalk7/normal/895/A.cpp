#include <iostream>
#include <fstream>
#define MAXN 370
using namespace std;
int N;
int a[MAXN];
int sum;
int best;
int main()
{
    cin>>N;
    best = 360;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
            for(int k=i; k<=j; k++)
            {
                sum += a[k];
            }
            best = min(best, max(360-2*sum, 2*sum-360));
            sum = 0;
        }
    }
    cout<<best<<endl;
}