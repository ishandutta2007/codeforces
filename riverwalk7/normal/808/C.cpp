#include <iostream>
#include <fstream>
#include <algorithm>
#define MAXN 110
using namespace std;
struct tea
{
    int a, b, c;
    tea()
    {
        a = b = c = 0;
    }
    bool operator <(const tea &rhs) const
    {
        return a > rhs.a;
    }
};
bool comp(tea s, tea t)
{
    return s.c < t.c;
}
int N, W;
tea x[MAXN];
int counter;
int main()
{
    cin>>N>>W;
    for(int i=0; i<N; i++)
    {
        cin>>x[i].a;
        x[i].b = (x[i].a+1)/2;
        W -= x[i].b;
        x[i].c = i;
    }
    if(W < 0)
    {
        cout<<-1<<endl;
        return 0;
    }
    sort(x, x+N);
    while(W > 0)
    {
        while(W > 0 && x[counter].b < x[counter].a)
        {
            x[counter].b++;
            W--;
        }
        counter++;
    }
    sort(x, x+N, comp);
    for(int i=0; i<N-1; i++)
    {
        cout<<x[i].b<<" ";
    }
    cout<<x[N-1].b<<endl;
}