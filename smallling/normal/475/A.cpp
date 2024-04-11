#include<cstdio>
#include<cstring>

using namespace std;

char a[110][30];
int bo,k;

void work(int x,char s[])
{
    int len=strlen(s);
    for(int i=0;i<len;i++)
        a[x][i]=s[i];
}

int main()
{
    work(1,"+------------------------+");
    work(2,"|#.#.#.#.#.#.#.#.#.#.#.|D|)");
    work(3,"|#.#.#.#.#.#.#.#.#.#.#.|.|");
    work(4,"|#.......................|");
    work(5,"|#.#.#.#.#.#.#.#.#.#.#.|.|)");
    work(6,"+------------------------+");
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        bo=0;
        for(int j=1;j<=22;j++)
        {
            for(int k1=1;k1<=6;k1++)
                if(a[k1][j]=='#')
                {
                    a[k1][j]='O';
                    bo=1;
                    break;
                }
            if(bo)break;
        }
    }
    for(int i=1;i<=6;i++)
        puts(a[i]);
}