#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#define M make_pair
#define L lower_bound
#define W second
using namespace std;
#define D double
map<D,D> f,g;
map<D,D>::iterator a,b,c;
int N;D y,e,z,d;
int main(){scanf("%d",&N);for (int i=1;i<=N;i++){scanf("%lf",&y);y+=D(i)/1000000;f.insert(M(y,i));g.insert(M(i,y));}d=0;e=0;for (int i=1;i<=N-2;i++){a=f.begin();z=a->W;b=g.L(z);c=b;++c;if ((b==g.begin())||(c==g.end())){d+=trunc(b->W-e)*(N-i-1);e=trunc(b->W);}else
{b--;d+=trunc(min(b->W,c->W))-e;b++;}f.erase(a);
g.erase(b);}
cout<<(long long)(round(d))<<endl;
return 0;
}