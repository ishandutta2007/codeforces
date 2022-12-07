#include <iostream>
#include <fstream>
#define MAXN 65536
using namespace std;
int N, K;
int a[16];
int cur;
int b;
int main()
{
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cur = 0;
        for(int j=0; j<K; j++)
        {
            cin>>b;
            if(b==1)
            {
                cur += (1<<j);
            }
        }
        a[cur]++;
    }
    for(int i=0; i<16; i++)
    {
        for(int j=0; j<16; j++)
        {
            if((i & j)==0 && a[i]!=0 && a[j]!=0)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}