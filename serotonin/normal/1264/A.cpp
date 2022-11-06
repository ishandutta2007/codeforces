#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+5;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        int med[3]={0}, now=0, pos=0;
        while(pos<n) {
            if(!pos) med[now]++, pos++;
            else {
                if(a[pos]==a[pos-1]) med[now]++, pos++;
                else {
                    if(!now) now++;
                    else if(now==1) {
                        if(med[now]>med[0]) now++;
                        else med[now]++, pos++;
                    }
                    else {
                        if(med[now]>med[0]) break;
                        else med[now]++, pos++;
                    }
                }
            }
        }

        if(pos>n/2) puts("0 0 0");
        else {
            int cut=0;
            for(int i=n/2; i; i--) {
                if(a[i-1]!=a[i]) {
                    cut=i;
                    break;
                }
            }
            if(cut) med[2]+=cut-pos;
            for(int i=0; i<3; i++) printf("%d ", med[i]);
            puts("");
        }
    }
}