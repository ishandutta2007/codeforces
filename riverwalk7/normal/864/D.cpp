#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 201000
using namespace std;
int frequency[MAXN];
bool vis[MAXN];
int a[MAXN];
vector<int> u;
int N;
int q, counter;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        frequency[a[i]]++;
        if(frequency[a[i]] > 1)
        {
            q++;
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(frequency[i] == 0)
        {
            u.push_back(i);
        }
    }
    u.push_back(10000000);
    counter = 0;
    for(int i=0; i<N; i++)
    {
        if(frequency[a[i]] > 1 && ((u[counter] < a[i])||(vis[a[i]])))
        {
            frequency[a[i]]--;
            a[i] = u[counter];
            ++counter;
        }
        else
        {
            vis[a[i]] = true;
        }
    }
    cout<<q<<endl;
    for(int i=0; i<N-1; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[N-1]<<endl;
}