#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 3e5+5;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=2; ; i++) {
        if(n%i==0) {
            cnt++;
            printf("%d", i);
            if(cnt > 1) exit(0);
            n/=i;
            i--;
        }
    }
}