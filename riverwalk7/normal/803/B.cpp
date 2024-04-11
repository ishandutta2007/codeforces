#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define MAXN 200100
using namespace std;
int N;
int a[MAXN];
vector<int> v;
int l, r;
int counter;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            v.push_back(i);
            if(v.size()==1)
            {
                r = i;
            }
        }
    }
    l = -1000000;
    counter = 1;
    for(int i=0; i<N; i++)
    {
        if(i<N-1)
        cout<<min(abs(i-l), abs(i-r))<<" ";
        else
        {
            cout<<min(abs(i-l), abs(i-r))<<endl;
        }
        if(i==r)
        {
            l = r;
            if(counter<v.size())
            {
                r = v[counter];
                counter++;
            }
            else
            {
                r = 1000000;
            }
        }
    }
}