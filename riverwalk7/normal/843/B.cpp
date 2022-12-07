#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
int N, start, x;
int s, t, v, n, b, c;
int hash_num(ll num)
{
    return (int)((num*29+12237)%N);
}
int main()
{
    cin>>N>>start>>x;
    time_t timer;
    time(&timer);
    s = hash_num(timer);
    srand(s);
    cout<<"? "<<start<<endl;
    fflush(stdout);
    cin>>v>>n;
    b = v; c = start;
    if(b >= x)
    {
        cout<<"! "<<b<<endl;
        return 0;
    }
    for(int i=0; i<999; i++)
    {
        t = rand() % N + 1;
        t = hash_num(hash_num(hash_num(hash_num(t)+hash_num(i)+hash_num(i))+hash_num(i))+hash_num(i)) + 1;
        cout<<"? "<<t<<endl;
        fflush(stdout);
        cin>>v>>n;
        if(b<v && v < x)
        {
            b = v;
            c = t;
        }
    }
    for(int i=0; i<999; i++)
    {
        cout<<"? "<<c<<endl;
        fflush(stdout);
        cin>>v>>n;
        if(v >= x)
        {
            cout<<"! "<<v<<endl;
            return 0;
        }
        c = n;
        if(c==-1)
        {
            cout<<"! "<<-1<<endl;
        }
    }
}