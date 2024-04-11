#include<bits/stdc++.h>
using namespace std;
bool check(int s, int p)
{s=(s/50)%475;
for (int i=0; i<25; i++)
{s=(s*96+42)%475;
if(s+26==p) return 1;
}
return 0;
}
int main()
{int x,y,p;
cin>>p>>x>>y;
int z=y+(x-y+10000)%50;
//cout<<z<<endl;
for (int i=z; i<=y+475*100; i+=50)
if (check(i,p)){cout<<max(0,(i-x+50)/100)<<endl; return 0;}
}