#include <iostream>
using namespace std;
int mp[4004][4004], cnt[4004];
int n, m, x[4004], y[4004];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        mp[x[i]][y[i]] = mp[y[i]][x[i]] = 1;
        cnt[x[i]]++; cnt[y[i]]++;
    }
    int res = 4004;
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            if(x[i]==x[j] && mp[y[i]][y[j]])
            {
                res = min(res, cnt[x[i]]+cnt[y[j]]+cnt[y[i]]-6);
            }
            if(x[i]==y[j] && mp[y[i]][x[j]])
            {
                res = min(res, cnt[x[i]]+cnt[y[i]]+cnt[x[j]]-6);
            }
            if(x[j]==y[i] && mp[y[j]][x[i]])
            {
                res = min(res, cnt[x[i]]+cnt[y[i]]+cnt[y[j]]-6);
            }
            if(x[j]==y[j] && mp[x[i]][y[i]])
            {
                res = min(res, cnt[x[i]]+cnt[y[i]]+cnt[y[j]]-6);
            }
        }
    }
    if(res == 4004) res = -1;
    cout << res << endl;
}