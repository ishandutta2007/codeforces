#include <stdio.h>
#include <vector>

#define MAX_N 50
using namespace std;


vector<int> vr, vc;
int N, M;
bool gp[MAX_N+10][MAX_N+10];
char c[MAX_N+1][MAX_N+10];

int gr[MAX_N+10], gc[MAX_N+10];


int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%s", c[i]);
        for(int j=0; j<M; j++)
        {
            if(c[i][j]=='#')
            {
                gp[i][j+1]=true;
            }
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(gr[i]==0)
        {
            for(int j=1; j<=M; j++)
            {
                if(gp[i][j])
                {
                    vc.push_back(j);
                }
            }
            if(!vc.empty())
            {
                for(int j=1; j<=N; j++)
                {
                    if(gp[j][vc.front()])
                    {
                        vr.push_back(j);
                    }
                }
                for(int k=0; k<vr.size(); k++)
                {
                    for(int j=0; j<vc.size(); j++)
                    {
                        if(!gp[vr[k]][vc[j]])
                        {
                            printf("No");
                            return 0;
                        }
                    }
                }
                for(int j=0; j<vr.size(); j++)
                {
                    gr[vr[j]]=i;
                }
                for(int j=0; j<vc.size(); j++)
                {
                    gc[vc[j]]=i;
                }
                for(int j=0; j<vr.size(); j++)
                {
                    for(int k=1; k<=M; k++)
                    {
                        if(gp[vr[j]][k] && gc[k]!=i)
                        {
                            printf("No");
                            return 0;
                        }
                    }
                }
                for(int j=0; j<vc.size(); j++)
                {
                    for(int k=1; k<=N; k++)
                    {
                        if(gp[k][vc[j]] && gr[k]!=i)
                        {
                            printf("No");
                            return 0;
                        }
                    }
                }
                vr.clear();
                vc.clear();
            }
        }
    }
    printf("Yes");
    return 0;
}