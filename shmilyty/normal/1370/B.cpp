#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
int main ()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        v1.clear(); 
        v2.clear();
        int n,ch;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++)
        {
            scanf("%d",&ch);
            if(ch%2==0)
                v1.push_back(i);
            else 
                v2.push_back(i);
        }
        if(v1.size()%2==1)
        {
           v1.pop_back();
           v2.pop_back();
        }
        else 
            if(v1.size()>=2)
            {
                v1.pop_back();
                v1.pop_back();
            }
        else 
        {
            v2.pop_back();
            v2.pop_back();
        }
        for(int i=0;i<v1.size();i+=2)
            printf("%d %d\n",v1[i],v1[i+1]);
        for(int i=0;i<v2.size();i+=2)
            printf("%d %d\n", v2[i],v2[i+1]);
    }
    return 0;
}