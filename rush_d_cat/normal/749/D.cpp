#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int NICO = 200002;
const int INF = 1e9+7;
vector<int> vec[NICO];
int n, xiong = 0;
int mx[NICO];
int hui[NICO];
int id[NICO];
int sta[NICO];
bool cmp(int a, int b){return mx[a] > mx[b];}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        mx[a] = b;
    }
    for(int i=1;i<NICO;i++) hui[i] = i;
    sort(hui+1,hui+NICO, cmp);
    int q;scanf("%d", &q);
    for(int i=1;i<=q;i++)
    {
        int t;scanf("%d", &t);
        for(int j=1;j<=t;j++)
        {
            int x; scanf("%d", &x);
            id[j] = x;
            sta[x] = i;
        }
        int idhui = 0, idgua = 0;
        for(int j=1;j<NICO;j++)
        {
            if(idgua || j >= t+3) break;
            if(mx[hui[j]] == 0) continue;
            if(sta[hui[j]] != i)
            {
                if(idhui == 0) idhui = hui[j];
                else if(idgua == 0) idgua = hui[j];
            }
        }
        if(idhui == 0) printf("0 0\n");
        else {
            int maxc;
            if(idgua == 0) maxc = -1;
            else maxc = mx[idgua];
            int res = *lower_bound(vec[idhui].begin(),vec[idhui].end(),maxc);
            printf("%d %d\n", idhui, res);
        }
    }
}