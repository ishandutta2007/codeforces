#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int T;
int k, arr[30], ans;

int main()
{
    ios_base::sync_with_stdio(false);

    scanf("%d", &T);
    while(T--)
    {
        int i, j;

        int s=0;
        ans=0;
        scanf("%d", &k);
        for(i=0; i<7; i++) { scanf("%d", &arr[i]); s+=arr[i]; }
        if(k%s==0) { ans+=7*(k/s-1); k=s; }
        else { ans+=7*(k/s); k%=s; }


        int minval=100;
        for(i=7; i<14; i++) arr[i]=arr[i-7];

        for(i=0; i<7; i++)
        {
            if(arr[i]!=1) continue;
            int cnt=0;
            for(j=i; cnt<k; j++) cnt+=arr[j];
            minval=min(minval, j-i);
        }
        printf("%d\n", ans+minval);
    }

    return 0;
}