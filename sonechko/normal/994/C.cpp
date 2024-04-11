#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double

const int N = 1e5 + 11;

int a[N],b[N],c[N],d[N];

ld dist(ld x1, ld y1, ld x2, ld y2)
{
          return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

ld pl(int x1, int y1, int x2, int y2, int x3, int y3)
{
          ld a=dist(x1,y1,x2,y2);
          ld b=dist(x1,y1,x3,y3);
          ld c=dist(x2,y2,x3,y3);
          ld p=(a+b+c)/(ld)2;
          return sqrt((p-a)*(p-b)*(p-c)*p);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i=1; i<=4; i++)
    cin>>a[i]>>b[i];
    a[5]=a[1];
    b[5]=b[1];
    for (int i=1; i<=4; i++)
    cin>>c[i]>>d[i];
    c[5]=c[1];
    d[5]=d[1];
    for (int ii=-100; ii<=100; ii++)
    for (int j=-100; j<=100; j++)
    {
              ld p1=pl(a[1],b[1],a[2],b[2],a[3],b[3])+pl(a[1],b[1],a[4],b[4],a[3],b[3]);
              for (int i=1; i<=4; i++)
              p1-=pl(a[i],b[i],a[i+1],b[i+1],ii,j);
              int ts=0;
              if (abs(p1)<=0.00000001) ts++;
              ld p2=pl(c[1],d[1],c[2],d[2],c[3],d[3])+pl(c[1],d[1],c[4],d[4],c[3],d[3]);
              for (int i=1; i<=4; i++)
              p2-=pl(c[i],d[i],c[i+1],d[i+1],ii,j);
              if (abs(p2)<=0.00000001) ts++;
              //if (ii>=0&&ii<=6&&j>=0&&j<=6) cout<<ii<<" "<<j<<" "<<ts<<endl;
              if (ts==2) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl;
}