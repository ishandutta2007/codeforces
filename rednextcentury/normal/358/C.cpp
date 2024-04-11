#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MIN(A,B)        (((A)<(B))?(A):(B))
#define read            freopen("C:\\Users\\USER\\Desktop\\in.txt", "r", stdin)
vector<int> v;
int A[100100];
int main()
{
    int i, j, k, n, temp, p, last;

    scanf("%d", &n);
    for (i=1; i<=n; i++) scanf("%d", &A[i]);

    A[0]=0;
    last=0;
    for (i=1; i<=n; i++)
    {
        if (A[i]==0)
        {
            if (v.size()==0) printf("0\n");
            else
            {
                sort(v.begin(), v.end());
                temp=0;

                    bool vis[3]={0};
                for (j=last+1; j<i; j++)
                {
                    int f=false;
                    for (k=0; k<MIN(v.size(), 3); k++)
                    {
                        if (!vis[k] && A[j]==-v[k])
                        {
                            vis[k]=1;
                            f=true;
                            break;
                        }
                    }
                    if (f)
                    {
                      if (temp==0) printf("pushStack\n");
                      if (temp==1) printf("pushQueue\n");
                      if (temp==2) printf("pushFront\n");

                        temp++;
                    }
                    else
                    {
                         printf("pushBack\n");
                    }
                }
            }

            if (v.size()>=3) printf("3 popStack popQueue popFront\n");
            else if (v.size()==2) printf("2 popStack popQueue\n");
            else if (v.size()==1) printf("1 popStack\n");

            last=i;
            v.clear();
        }
        else
        {
            v.push_back(-A[i]);
        }
    }
    for (i=last+1; i<=n; i++) printf("pushFront\n");
//file?
return 0;
}