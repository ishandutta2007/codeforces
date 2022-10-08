#include<cstdio>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
//1 k1 2 k2 3 k3
//10 c1 20 c2 30 c3
typedef pair<pair<ll,int>,int> event;
int k1,k2,k3,t1,t2,t3,n;
priority_queue<event> e;
queue<event> p1,p2,p3;
#define MP make_pair
ll S=0;
int main()
{
    scanf("%d%d%d%d%d%d%d",&k1,&k2,&k3,&t1,&t2,&t3,&n);
    for(int i=0,x;i<n;i++)scanf("%d",&x),e.push(MP(MP(-x,10),x));
    while(!e.empty())
    {
        event x=e.top();e.pop();
        S=max(S,-x.first.first-x.second);
        if(x.first.second==10)
        {
            if(k1>0){k1--;e.push(MP(MP(x.first.first-t1,1),x.second));}
            else p1.push(x);
        }else
        if(x.first.second==20)
        {
            if(k2>0){k2--;e.push(MP(MP(x.first.first-t2,2),x.second));}
            else p2.push(x);
        }else
        if(x.first.second==30)
        {
            if(k3>0){k3--;e.push(MP(MP(x.first.first-t3,3),x.second));}
            else p3.push(x);
        }else
        if(x.first.second==1)
        {
            k1++;
            e.push(MP(MP(x.first.first,20),x.second));
            if(!p1.empty())
            {
                event y=p1.front();
                p1.pop();
                k1--;
                e.push(MP(MP(x.first.first-t1,1),y.second));
            }
        }else
        if(x.first.second==2)
        {
            k2++;
            e.push(MP(MP(x.first.first,30),x.second));
            if(!p2.empty())
            {
                event y=p2.front();
                p2.pop();
                k2--;
                e.push(MP(MP(x.first.first-t2,2),y.second));
            }
        }else
        if(x.first.second==3)
        {
            k3++;
            if(!p3.empty())
            {
                event y=p3.front();
                p3.pop();
                k3--;
                e.push(MP(MP(x.first.first-t3,3),y.second));
            }
        };
    }
    cout<<S<<endl;
    return 0;
}