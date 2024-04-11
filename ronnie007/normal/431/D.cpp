#include<cstdio>
#include<cassert>

using namespace std;

#define linf 2000000000000000000LL
#define bit(mask,i) ((mask>>i)&1)

const int Max_Bit = 63;

long long C[Max_Bit+1][Max_Bit+1];

int bcount(long long x){
    int Res = 0;
    for (;x;x&=(x-1)) Res++;
    return Res;
}
long long Solve(long long x,int k){
            long long Answer = (k == bcount(x));
            for (int i = Max_Bit; i >= 0 && k>=0; i -- )
             if (bit(x,i)) 
              Answer+=C[i][k--];
            return Answer;
}
int main()
{
    C[0][0] = 1;
    for (int i = 1; i <= Max_Bit ;i ++ )
     for (int j = 0 ; j <= i ; j ++ )
      C[i][j]=C[i-1][j]+((j)?(C[i-1][j-1]):0);

    long long count;
    int k;
    scanf("%lld%d",&count,&k);

    
    long long l = 1 , r = linf/2;
    while (l<r)
    {
          long long m = l + (r-l)/2;
          if (Solve(m*2,k)-Solve(m,k)<count) l = m+1;
          else
           r = m;
    }
    
    printf("%I64d\n",l);
    return 0;
}