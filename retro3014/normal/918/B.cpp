#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

struct S{
    char c[20];
    int a[4];
    bool operator <(const S &t) const{
        return a<t.a;
    }
};
S k;
char c2[20];
int l;
long long tmp;
vector<S> v;
int cnt=0;

bool sf(S a1, S a2)
{
    return a1.a<a2.a;
}

int _find()
{
    bool tf=true;
    for(int i=0; i<v.size(); i++)
    {
        tf=true;
        for(int j=0; j<4; j++)
        {
            if(v[i].a[j]!=k.a[j])
            {
                tf=false;
            }
        }
        if(tf)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%s", k.c);
        scanf("%s", c2);
        l=(int)strlen(c2);
        tmp=0;
        k.a[0]=0;
        cnt=0;
        for(int i=0; i<l; i++)
        {
            //printf("%c", c2[i]);
            if(c2[i]=='.')
            {
                cnt++;
                k.a[cnt]=0;
            }
            else
            {
                k.a[cnt]=k.a[cnt]*10+c2[i]-'0';
            }
        }
        v.push_back(k);
    }
    int cnt=0;
    for(int i=1; i<=M; i++)
    {
        scanf("%s", k.c);
        scanf("%s", c2);
        l=(int)strlen(c2);
        tmp=0;
        k.a[0]=0;
        cnt=0;
        for(int i=0; i<l-1; i++)
        {
            if(c2[i]=='.')
            {
                cnt++;
                k.a[cnt]=0;
            }
            else
            {
                k.a[cnt]=k.a[cnt]*10+c2[i]-'0';
            }
        }
        int idx=_find();
        printf("%s %s #%s\n", k.c, c2, v[idx].c);
    }
}