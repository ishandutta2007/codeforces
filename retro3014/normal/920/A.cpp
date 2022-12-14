#include <stdio.h>
#include <deque>


using namespace std;
int T, N, M;
deque<int> dq;
int cnt;
bool chk[201];
bool tchk[201];

int main()
{
    scanf("%d", &T);
    while(T>0)
    {
        int i;
        T--;
        scanf("%d %d", &N, &M);
        for(int i=0; i<=N+1; i++)
        {
            chk[i]=0;
        }
        for(int i=1; i<=M; i++)
        {
            int k;
            scanf("%d", &k);
            chk[k]=true;
        }
        for(i=1; ; i++)
        {
            int c=0;
            for(int j=1; j<=N; j++)
            {
                if(chk[j])
                {
                    c++;
                }
            }
            if(c==N)
            {
                break;
            }
            for(int j=1; j<=N; j++)
            {
                tchk[j]=chk[j-1]|chk[j]|chk[j+1];
            }
            for(int j=1; j<=N; j++)
            {
                chk[j]=tchk[j];
            }
        }
        printf("%d\n", i);
    }
    return 0;
}