#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
int N;
int a[MAXN];
int b[MAXN];
bool l[MAXN];
int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        b[a[i]] = i;
    }
    for(int i=N; i>=1; i--)
    {
        l[i] = true;
        for(int j = b[i] % i; j <= N; j += i)
        {
            if(l[a[j]]&&a[j]!=i)
            {
                l[i] = false;
            }
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(l[a[i]])
        {
            cout<<'B';
        }
        else
        {
            cout<<'A';
        }
    }
}