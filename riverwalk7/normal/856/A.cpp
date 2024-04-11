#include <iostream>
#include <fstream>
#define MAXN 1100000
#define MAXK 110
using namespace std;
bool used[MAXN];
int a[MAXK];
int counter, cur;
int t, N;
int main()
{
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>N;
        counter = 1;
        for(int j=0; j<N; j++)
        {
            cin>>a[j];
        }
        cout<<"YES"<<endl;
        for(int j=0; j<N; j++)
        {
            while(used[counter])
            {
                ++counter;
            }
            for(int k=0; k<N; k++)
            {
                for(int l=0; l<N; l++)
                {
                    cur = counter+a[k]-a[l];
                    if(1<=cur && cur < MAXN)
                    {
                        used[cur] = true;
                    }
                }
            }
            if(j<N-1)
                cout<<counter<<" ";
        }
        cout<<counter<<endl;
        for(int j=0; j<MAXN; j++)
        {
            used[j] = false;
        }
    }
}