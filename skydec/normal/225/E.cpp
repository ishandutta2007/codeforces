#include<stdio.h>
using namespace std;
int q[42]={0,1, 2, 4, 6, 12, 16, 18, 30, 60, 88, 106, 126, 520, 606, 1278, 2202, 2280, 3216, 4252, 4422, 9688, 9940, 11212, 19936, 21700, 23208, 44496, 86242, 110502, 132048, 216090, 756838, 859432, 1257786, 1398268, 2976220, 3021376, 6972592, 13466916,20996010};
int n;
#define jsb 1000000007
int main()
{
    scanf("%d",&n);
    int ans=1;n=q[n];
    while(n--)ans=ans*2ll%jsb;ans--;
    if(ans<0)ans+=jsb;
    printf("%d\n",ans);
    return 0;
}