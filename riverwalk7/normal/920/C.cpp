#include <iostream>
#include <fstream>
#define MAXN 200100
using namespace std;
int l[MAXN], r[MAXN];
int N;
int a[MAXN];
char c;
bool s[MAXN];
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<N-1; i++)
    {
        cin>>c;
        if(c=='1')
        {
            s[i] = true;
        }
    }
    for(int i=0; i<N-1; i++)
    {
        if(s[i])
        {
            l[i+1] = l[i];
        }
        else
        {
            l[i+1] = i+1;
        }
    }
    r[N-1] = N-1;
    for(int i=N-2; i>=0; i--)
    {
        if(s[i])
        {
            r[i] = r[i+1];
        }
        else
        {
            r[i] = i;
        }
    }
    for(int i=0; i<N; i++)
    {
        a[i]--;
        if(!(l[i]<=a[i]&&a[i]<=r[i]))
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}