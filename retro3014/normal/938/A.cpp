#include <stdio.h>

bool calc(char cc)
{
    if (cc=='a' || cc=='e' || cc=='i' || cc=='o' || cc=='u' || cc=='y')
    {
        return true;
    }
    return false;
}

int main()
{
    int N;
    char c[200];
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++)
    {
        scanf("%c", &c[i]);
        if(i==0 || !calc(c[i]) || !calc(c[i-1]))
        {
            printf("%c", c[i]);
        }
    }
    return 0;
}