#pragma comment(linker, "/STACK:64000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#define NAME "test"
using namespace std;
typedef long long int li;
typedef vector<int> vi;
int main(){
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    struct date{
        int d,m,y;
        date(){};
        date(int D,int M,int Y){
            d=D;
            m=M;
            y=Y;
            if(m>12 || d>31 || (d==31 && (m==2 ||m==4 || m==6 || m==9 || m==11)) || (d==30 && m==2) || (d==29 && m==2 && y%4)){
                d=99;
                m=99;
                y=99;
            }
        }
        bool operator -(const date &b ){
            date c=*this;
            c.y-=b.y;
            c.m-=b.m;
            c.d-=b.d;
            if(c.d<0)
                c.m--;
            if(c.m<0)
                c.y--;
            if(c.y>=18)
                return true;
            return false;
        }
    };
    int a,b,c;
    scanf("%d.%d.%d",&a,&b,&c);
    date f(a,b,c);
    scanf("%d.%d.%d",&a,&b,&c);
    if(f-date(a,b,c)||f-date(a,c,b)||f-date(b,a,c)||f-date(b,c,a)||f-date(c,a,b)||f-date(c,b,a))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}