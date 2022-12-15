#include<iostream>
#include<cstdlib>
#include<cstdio>
#include <time.h>

using namespace std;

unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

bool b[50001];
long long br;

int main ()
{
    long long n,start,x,p,nextp,k,p2,nextp2,i,q;
    bool y=false;

    srand (time(NULL));

    cin>>n>>start>>x;

    cout<<"? "<<start<<endl;
    fflush(stdout);

    cin>>p>>nextp;

    if(p>=x)
    {
        cout<<"! "<<p<<endl;
        fflush(stdout);
        return 0;
    }

    for(i=0;i<1000;i++)
    {
        k=llrand()%n+1;
        while(k<1)k+=n;
        while(b[k]==1)
        {
            k=rand()%n+1;
            while(k<0)k+=n;
            br++;
            if(br==20)break;
        }
        if(br==20)break;
        cout<<"? "<<k<<endl;
        fflush(stdout);
        cin>>p2>>nextp2;
        if(p2>p && p2<x)
        {
            p=p2;
            nextp=nextp2;
        }
        if(p2>=x)
        {
            if(y==false)
            {
                q=p2;
                y=true;
            }
            else
            {
                if(p2<q)q=p2;
            }
        }
    }

    for(i=0;i<990;i++)
    {
        if(p>=x)
        {
            cout<<"! "<<p<<endl;
            fflush(stdout);
            return 0;
        }
        if(nextp==-1)break;
        cout<<"? "<<nextp<<endl;
        fflush(stdout);
        cin>>p>>nextp;
    }
    if(y==true)
    {
        cout<<"! "<<q<<endl;
        fflush(stdout);
        return 0;
    }
    cout<<"! -1"<<endl;
    fflush(stdout);

    return 0;
}