//program 143A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  int r1,r2,c1,c2,d1,d2;
  scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
  int A=(c1+d1-r2)/2,B=r1-A,C=c1-A,D=d1-A;
  if(B+C==d2&&B+D==c2&&C+D==r2&&A>0&&A<10&&B>0&&B<10&&C>0&&C<10&&D>0&&D<10&&A!=B&&A!=C&&A!=D&&B!=C&&B!=D&&C!=D)
    printf("%d %d\n%d %d\n",A,B,C,D);
  else
    printf("-1\n");
  return 0;
}