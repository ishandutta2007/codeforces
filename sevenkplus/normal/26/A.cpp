#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int n;vector<int> a;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        bool F=0;
        for(int j=2;j*j<=i;j++)F|=(i%j==0);
        if(!F)a.push_back(i);
    }
    int S=0;
    for(int i=1;i<=n;i++)
    {
        int F=0;
        for(int j=0;j<a.size();j++)F+=(i%a[j]==0);
        if(F==2)S++;
    }
    printf("%d\n",S);
    return 0;
}