#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
int l[MAXN], r[MAXN];
int a[MAXN], b[MAXN];
int N, T;
int cur;
int bl[2*MAXN], br[2*MAXN];
int tot, ans;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        tot = 2*N;
        for(int i=0; i<N; i++)
        {
            cin>>a[N-i-1];
            if(a[N-i-1] == 1) tot -= 1;
            else tot += 1;
        }
        for(int i=0; i<N; i++)
        {
            cin>>b[i];
            if(b[i] == 1) tot -= 1;
            else tot += 1;
        }
        cur = N;
        for(int i=0; i<2*MAXN; i++)
        {
            bl[i] = br[i] = 2*MAXN;
        }
        bl[N] = br[N] = 0;
        for(int i=0; i<N; i++)
        {
            if(a[i] == 1) cur -= 1;
            else cur += 1;
            bl[cur] = min(bl[cur], i+1);
        }
        cur = N;
        for(int i=0; i<N; i++)
        {
            if(b[i] == 1) cur -= 1;
            else cur += 1;
            br[cur] = min(br[cur], i+1);
        }
        ans = 2*MAXN;
        for(int i=0; i<=tot; i++)
        {
            ans = min(ans, bl[i]+br[tot-i]);
        }
        cout<<ans<<endl;
    }
}