/*
ID: Sfiction
OJ: CF
PROB: 271D
*/
#include <cstdio>
int N;
char a[128];
char s[1502];
struct trie
{
    char chr,mark;
    trie *son[26];
};
void Initialize(trie *x)
{
    int i;
    x->chr=x->mark=0;
    for (i=0;i<26;++i) x->son[i]=NULL;
}
int main()
{
    int i,j,K;
    int num,sum;
    trie *sta=new trie,*t;
    Initialize(sta);
    scanf("%s",s);
    getchar();
    for (i=97;i<123;++i) scanf("%c",&a[i]);
    scanf("%d",&K);
    sum=0;
    for (i=0;s[i];++i)
    {
        num=0;
        t=sta;
        for (j=i;s[j];++j)
        {
            if (t->son[s[j]-97]==NULL)
            {
                t->son[s[j]-97]=new trie;
                Initialize(t->son[s[j]-97]);
                t->son[s[j]-97]->chr=s[j];
            }
            num+=a[s[j]]=='0';
            t=t->son[s[j]-97];
            if (num<=K&&t->mark==0)
            {
                ++sum;
                t->mark=1;
            }
        }
    }
    printf("%d",sum);
    return 0;
}