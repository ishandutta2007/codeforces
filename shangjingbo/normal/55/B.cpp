#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

vector<long long>a;
vector<char> op;
long long Ans;

inline void dfs(vector<long long> a,vector <char> b)
{
    if (a.size()==1)
    {
        Ans=min(Ans,a[0]);
        return;
    }
    for (int i=0;i<a.size();++i)
        for (int j=i+1;j<a.size();++j)
            for (int k=0;k<1;++k)
            {
                long long x=a[i];
                if (b[k]=='+') x+=a[j];
                else x*=a[j];
                
                vector<long long> aa;
                vector<char> bb;
                aa.clear();
                bb.clear();
                for (int p=0;p<a.size();++p)
                if (p!=i && p!=j) aa.PB(a[p]);
                aa.PB(x);
                
                for (int p=0;p<b.size();++p)
                if (p!=k) bb.PB(b[p]);
                
                dfs(aa,bb);
            }
}

int main()
{
    a.resize(4);
    for (int i=0;i<4;++i)
        scanf("%d",&a[i]);
    
    op.resize(3);
    for (int i=0;i<3;++i)
    {
        char s[10];
        scanf("%s",s);
        op[i]=s[0];
    }
    
    Ans=1000000000000000000LL;
    
    dfs(a,op);
    
    cout << Ans << endl;
    
    return 0;
}