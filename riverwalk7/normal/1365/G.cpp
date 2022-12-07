#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 1010
using namespace std;
typedef long long ll;
const int Q = 13;
int N;
ll b[Q];
int k[MAXN];
int counter;
ll cur;
int main()
{
    cin>>N;
    for(int i=0; counter < N; i++)
    {
        int counter2 = 0;
        for(int j=0; j<Q; j++)
        {
            if((1<<j) & i)
            {
                ++counter2;
            }
        }
        if(counter2 == 6)
        {
            ++counter;
            k[counter] = i;
        }
    }
    for(int i=0; i<Q; i++)
    {
        int counter2 = 0;
        for(int j=1; j<=N; j++)
        {
            if(k[j] & (1<<i))
            {
                ++counter2;
            }
        }
        if(counter2 == 0) break;
        cout<<"? ";
        cout<<counter2<<" ";
        for(int j=1; j<=N; j++)
        {
            if(k[j] & (1<<i))
            {
                cout<<j<<" ";
            }
        }
        cout<<""<<endl;
        cin>>b[i];
    }
    cout<<"! ";
    for(int i=1; i<=N; i++)
    {
        cur = 0;
        for(int j=0; j<Q; j++)
        {
            if(!((1<<j) & k[i]))
            {
                cur = cur | b[j];
            }
        }
        cout<<cur<<" ";
        cout<<""<<endl;
    }
}