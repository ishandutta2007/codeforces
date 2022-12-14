#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_N 1000000

int N;
int arr[MAX_N+1];
int pos[MAX_N+1];
int cnt;

int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
        pos[arr[i]]=i;
    }
    for(int i=1; i<=N; i++)
    {
        if(pos[i]!=i)
        {
            int tmp=i;
            arr[pos[i]]=arr[i];
            arr[i]=tmp;
            pos[arr[pos[i]]]=pos[i];
            pos[i]=i;
            cnt++;
        }
    }
    if(N%2)
    {
        if(cnt%2)
        {
            cout<<"Petr";
        }
        else
        {
            cout<<"Um_nik";
        }
    }
    else
    {
        if(cnt%2)
        {
            cout<<"Um_nik";
        }
        else
        {
            cout<<"Petr";
        }
    }
    return 0;
}