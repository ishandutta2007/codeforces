#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0, f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int M = 100016, MOD = 1000000007;
const int MAXN = 3e5 + 5;

char s[MAXN];

namespace solve
{
    char id[MAXN];
    int num[MAXN];

    int solve()
    {
        int cur = -1;
        for (int i = 0; s[i]; ++i)
        {
            if (i == 0 || s[i] != s[i - 1])
                id[++cur] = s[i];
            ++num[cur];
        }
        for (int i = 0, j = cur; ; ++i, --j)
        {
            if (i > j)
                return 0;
            if (i == j)
                return num[i] == 1 ? 0 : num[i] + 1;
            if (id[i] != id[j] || num[i] + num[j] < 3)
                return 0;
        }

        return 0;
    }
}

void init()
{
	scanf("%s", s);
}

int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif

	init();
	printf("%d", solve::solve());

	return 0;
}